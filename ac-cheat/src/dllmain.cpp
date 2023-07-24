#include "pch.h"
#include "Global.h"
#include "Functions.h"
#include "Hook.h"
#include "Util.h"
#include "Features.h"
#include "Begin.h"


DWORD WINAPI HackThread(HMODULE hModule)
{
	Util::CreateConsole();
	
	Begin();

	Util::DestroyConsole();
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