#include "pch.h"
#include "Features.h"
#include "pch.h"
#include "Global.h"
#include "Hook.h"
#include "Player.h"

void Feature::Menu()
{

	std::cout << "[ Buuu Internal Hack ]" << '\n';
	std::cout << '\n';
	std::cout << "[ F1 ]" << "Godmode" << '\n';
	std::cout << "[ F2 ]" << "Infinite Ammo" << '\n';
	std::cout << "[ F3 ]" << "RapidFire" << '\n'; 
}

void Feature::godMode()
{
	if (GetAsyncKeyState(VK_F1) & 1)
	{
		toggle::GodMode = !toggle::GodMode;

		if (toggle::GodMode)
		{
			Detour((VOID*)0x429D1F, godmode, hooklen::Godmode);
		}
	}

}

void Feature::rapidFire()
{
	if (GetAsyncKeyState(VK_F3) & 1)
	{
		toggle::RapidFire = !toggle::RapidFire;

		if (toggle::RapidFire)
		{
			Detour((VOID*)0x4637E4, rapidfire, hooklen::RapidFire);
		}
	}

}

void Feature::infiteAmmo()
{

	if (GetAsyncKeyState(VK_F2) & 1)
	{
		toggle::InfiniteAmmo = !toggle::InfiniteAmmo;

		if (!toggle::InfiniteAmmo)
		{
			// Restore the original ammo value when infinite ammo is toggled off
			if (original::AmmoSet)
			{
				localPlayer->CurrentWeapon->MagAmmo->ammo = original::Ammo;
				original::AmmoSet = false;
			}
		}
		else
		{
			// Set the original ammo value only once when toggling infinite ammo on
			if (!original::AmmoSet)
			{
				original::Ammo = localPlayer->CurrentWeapon->MagAmmo->ammo;
				original::AmmoSet = true;
			}
		}
	}

	if (toggle::InfiniteAmmo)
	{
		localPlayer->CurrentWeapon->MagAmmo->ammo = 1337;
	}

}


