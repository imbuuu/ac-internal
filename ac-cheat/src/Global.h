#pragma once
#include "Player.h"

extern Player* localPlayer;

// static addresses
namespace base
{
	extern uintptr_t moduleBase;
	extern uintptr_t localPlayerPtr;
	extern uintptr_t localPlayer;
	extern uintptr_t weaponbase;
}

// static addresses of instructions
namespace instruction
{
	extern uintptr_t AmmoDec;
	extern uintptr_t PlayerDamage;
}

namespace hooklen
{
	extern UINT Godmode;
	extern UINT RapidFire;
	extern UINT InfiniteAmmo;
}

namespace jmpbackaddy
{
	extern uintptr_t GodMode;
	extern uintptr_t RapidFire;
	extern uintptr_t InfiniteAmmo;
}

namespace toggle
{
	extern BOOL GodMode;
	extern BOOL RapidFire;
	extern BOOL InfiniteAmmo;
}

namespace original
{
	extern bool AmmoSet;
	extern unsigned int Ammo;
}
