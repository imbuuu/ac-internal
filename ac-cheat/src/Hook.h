#pragma once
#include "pch.h"

BOOL Detour(VOID* target, VOID* ourFunc, UINT len);

void godmode();

void rapidfire();

extern DWORD jmpBackAddyGodMode;

extern DWORD jmpBackAddyRapidFire;