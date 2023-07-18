#include "pch.h"
#include "Global.h"
#include "Functions.h"
#include "Hook.h"


DWORD WINAPI HackThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	uintptr_t ammoAddr = FindDMAAddy(base::localPlayerPtr, { 0x374, 0x14, 0x0 });

	std::cout << std::hex;
	std::cout << "Local Player Ptr: " << base::localPlayerPtr << '\n';
	std::cout << "Local Player: " << base::localPlayer << '\n';

	UINT hookLenGodmode = 5;
	UINT hookLenRapidFire = 5;

	jmpBackAddyGodMode = 0x429D1F + hookLenGodmode;
	jmpBackAddyRapidFire = 0x4637E4 + hookLenRapidFire;

	Detour((VOID*)0x429D1F, godmode, hookLenGodmode);

	Detour((VOID*)0x4637E4, rapidfire, hookLenRapidFire);

	while (true)
	{
		// Nop((DWORD*)instruction::AmmoDec, 2);

		// Patch((DWORD*)instruction::AmmoDec, (BYTE*)"\xFF\x06", 2);

		// *(uintptr_t*)ammoAddr = 1337;

		Sleep(100);
	}





	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);

	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}