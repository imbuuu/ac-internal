#pragma once
#include "pch.h"
#include "Vector.h"

// Created with ReClass.NET 1.2 by KN4CK3R

class Player
{
public:
	char pad_0000[4]; //0x0000
	Vector3 HeadPos; //0x0004
	char pad_0010[36]; //0x0010
	Vector3 Postion; //0x0034
	char pad_0040[8]; //0x0040
	Vector3 ViewAngle; //0x0048
	int32_t AirTime; //0x0054
	char pad_0058[20]; //0x0058
	bool bCrouch; //0x006C
	char pad_006D[139]; //0x006D
	int32_t Health; //0x00F8
	int32_t Armor; //0x00FC
	char pad_0100[20]; //0x0100
	int32_t PistolClip; //0x0114
	char pad_0118[16]; //0x0118
	int32_t AssRifleClip; //0x0128
	char pad_012C[16]; //0x012C
	int32_t PistolAmmo; //0x013C
	char pad_0140[36]; //0x0140
	int32_t PistolWait; //0x0164
	char pad_0168[16]; //0x0168
	int32_t AssRileWait; //0x0178
	char pad_017C[16]; //0x017C
	int32_t PistolShots; //0x018C
	char pad_0190[16]; //0x0190
	int32_t AssRifleShots; //0x01A0
	char pad_01A4[464]; //0x01A4
	class Weapon* CurrentWeapon; //0x0374
	char pad_0378[3296]; //0x0378
}; //Size: 0x1058
static_assert(sizeof(Player) == 0x1058);

class N00000479
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044
static_assert(sizeof(N00000479) == 0x44);

class Weapon
{
public:
	char pad_0000[4]; //0x0000
	int32_t ID; //0x0004
	class N000005A3* Owner; //0x0008
	class N000005B7* GunInfo; //0x000C
	class N000005CB* ClipAmmo; //0x0010
	class CurrentAmmo* MagAmmo; //0x0014
	char pad_0018[680]; //0x0018
	class N00000613* PtrToGameFile; //0x02C0
	char pad_02C4[384]; //0x02C4
}; //Size: 0x0444
static_assert(sizeof(Weapon) == 0x444);

class N000005A3
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044
static_assert(sizeof(N000005A3) == 0x44);

class N000005B7
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044
static_assert(sizeof(N000005B7) == 0x44);

class N000005CB
{
public:
	int32_t Clip; //0x0000
	char pad_0004[76]; //0x0004
	int32_t ReloadWait; //0x0050
	char pad_0054[36]; //0x0054
	int32_t ShotsFired; //0x0078
	char pad_007C[1992]; //0x007C
}; //Size: 0x0844
static_assert(sizeof(N000005CB) == 0x844);

class CurrentAmmo
{
public:
	int32_t ammo; //0x0000
	char pad_0004[2112]; //0x0004
}; //Size: 0x0844
static_assert(sizeof(CurrentAmmo) == 0x844);

class N000005E9
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044
static_assert(sizeof(N000005E9) == 0x44);

class N000005FE
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044
static_assert(sizeof(N000005FE) == 0x44);

class N00000613
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044
static_assert(sizeof(N00000613) == 0x44);