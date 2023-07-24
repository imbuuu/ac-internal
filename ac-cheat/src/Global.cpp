#include "pch.h"
#include "Global.h"
#include "Functions.h"



uintptr_t instruction::AmmoDec = 0x4637E9;
uintptr_t instruction::PlayerDamage = 0x4E4AA8;

uintptr_t base::moduleBase = (uintptr_t)GetModuleHandle(NULL);

uintptr_t base::localPlayerPtr = moduleBase + 0x10f4f4;
uintptr_t base::localPlayer = *(uintptr_t*)localPlayerPtr;
uintptr_t base::weaponbase = FindDMAAddy(localPlayerPtr, { 0x374, 0x0 });

Player* localPlayer = *(Player**)base::localPlayerPtr;

// Hook length
UINT hooklen::Godmode = 5;
UINT hooklen::RapidFire = 5;
UINT hooklen::InfiniteAmmo = 7;

// Jump back address
uintptr_t jmpbackaddy::GodMode = 0x429D1F + hooklen::Godmode;
uintptr_t jmpbackaddy::RapidFire = 0x4637E4 + hooklen::RapidFire;
uintptr_t jmpbackaddy::InfiniteAmmo = 0x4637E9 + hooklen::InfiniteAmmo;

BOOL toggle::GodMode = FALSE;
BOOL toggle::RapidFire = FALSE;
BOOL toggle::InfiniteAmmo = FALSE;

// Original values
bool original::AmmoSet = false;
unsigned int original::Ammo = localPlayer->CurrentWeapon->MagAmmo->ammo;

