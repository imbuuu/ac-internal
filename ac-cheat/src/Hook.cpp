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
	
	memset(target, 0x90, len);
	DWORD relativeAddress = ((DWORD)ourFunc - (DWORD)target) - 5;

	*(BYTE*)target = 0xE9;
	*(DWORD*)((DWORD)target + 1) = relativeAddress;

	VirtualProtect(target, len, oldProtect, &oldProtect);

	return TRUE;
}

// Jump Back Addresses
DWORD jmpBackAddyGodMode;
DWORD jmpBackAddyRapidFire;

// Hook Functions
void __declspec(naked) godmode()
{
	__asm
	{
		cmp[ebx], 0x4E4AA8 // 799A5018
		jne original
		mov eax, edi
		jmp[jmpBackAddyGodMode]

		original:
		sub[ebx + 0x04], edi
		mov eax, edi
		jmp [jmpBackAddyGodMode]
	}
}

void __declspec(naked) rapidfire()
{
	__asm
	{
		cmp esi, base::weaponbase
		jne label1
		mov esi, [esi + 0x14]
		jmp[jmpBackAddyRapidFire]

		label1:
		mov[edx], ecx
		mov esi, [esi + 0x14]
		jmp[jmpBackAddyRapidFire]
	}
}