#include "pch.h"
#include "Global.h"
#include "Functions.h"

uintptr_t instruction::AmmoDec = 0x4637E9;
uintptr_t instruction::PlayerDamage = 0x4E4AA8;

uintptr_t base::moduleBase = (uintptr_t)GetModuleHandle(NULL);

uintptr_t base::localPlayerPtr = moduleBase + 0x10f4f4;
uintptr_t base::localPlayer = *(uintptr_t*)localPlayerPtr;
uintptr_t base::weaponbase = FindDMAAddy(localPlayerPtr, { 0x374, 0x0 });