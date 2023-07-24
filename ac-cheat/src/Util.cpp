#include "pch.h"
#include "Util.h"
#include "Global.h"


void Util::CreateConsole()
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
}

void Util::DestroyConsole()
{
	FreeConsole();
}

void Util::LogData(std::string dataName, VOID* pData)
{
	std::cout << '\n' << "[ LOG ] ";
	std::cout << std::hex;
	std::cout << dataName << pData << '\n';
}


