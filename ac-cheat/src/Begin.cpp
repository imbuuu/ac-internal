#include "pch.h"
#include "Begin.h"
#include "Global.h"
#include "Features.h"

// Main hack loop
void Begin()
{
	Feature feature;

	feature.Menu();

	while (!GetAsyncKeyState(VK_END) & 1)
	{
		Feature::godMode();

		Feature::infiteAmmo();

		Feature::rapidFire();
	}

}
	

