#include "pch.h"
#include "Hook.h"
#include "Global.h"

BOOL Detour(VOID* target, VOID* ourFunc, UINT len)
{
	if (len < 5)
	{
		return false;
	}

	DWORD oldProtect;
	VirtualProtect(target, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	
	memset(target, 0x90, len); // optional
	DWORD relativeAddress = ((DWORD)ourFunc - (DWORD)target) - 5;

	*(BYTE*)target = 0xE9;
	*(DWORD*)((DWORD)target + 1) = relativeAddress;

	VirtualProtect(target, len, oldProtect, &oldProtect);

	return TRUE;
}


// Hook Functions
void __declspec(naked) godmode()
{
	__asm
	{
		cmp [toggle::GodMode], 1
		jne originalcode
		cmp[ebx], 0x4E4AA8 // 799A5018
		jne originalcode
		mov eax, edi
		jmp[jmpbackaddy::GodMode]

		originalcode:
		sub[ebx + 0x04], edi
		mov eax, edi
		jmp [jmpbackaddy::GodMode]
	}
}


void __declspec(naked) rapidfire()
{
	__asm
	{
		cmp[toggle::RapidFire], 1
		jne originalcode
		cmp esi, base::weaponbase
		jne originalcode
		mov esi, [esi + 0x14]
		jmp[jmpbackaddy::RapidFire]

		originalcode:
		mov[edx], ecx
		mov esi, [esi + 0x14]
		jmp[jmpbackaddy::RapidFire]
	}
}


// Need to fix this -- Currently not working
void __declspec(naked) infiniteammo()
{
	__asm
	{
		//013FA850
		cmp [esi], 0x2A2A878
		jne originalcode
		nop
		nop
		push edi
		mov edi, [esp + 0x14]
		jmp[jmpbackaddy::InfiniteAmmo]

		originalcode:
		dec[esi]
		push edi
		mov edi, [esp + 0x14]
		jmp[jmpbackaddy::InfiniteAmmo]
	}
}