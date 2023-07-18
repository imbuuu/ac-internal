#pragma once
#include "pch.h"

void Nop(PVOID dst, SIZE_T size);

void Patch(PVOID dst, BYTE* src, SIZE_T size);

uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<UINT> offset);