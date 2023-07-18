#include "pch.h"
#include "Functions.h"

void Nop(PVOID dst, SIZE_T size)
{
	DWORD oldProtect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldProtect, &oldProtect);
}

void Patch(PVOID dst, BYTE* src, SIZE_T size)
{
	DWORD oldProtect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(dst, src, size);
	VirtualProtect(dst, size, oldProtect, &oldProtect);
}

uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<UINT> offset)
{
	uintptr_t addr = ptr;

	for (int i = 0; i < offset.size(); ++i)
	{
		addr = *(uintptr_t*)addr;
		addr += offset[i];
	}

	return addr;
}



// ac_client.exe + 637E9 - FF 0E - dec[esi]
// ac_client.exe+637EB - 57 - push edi

