#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "irrKlang.lib")
#endif

#if defined(WIN32)
#include <conio.h>
#else
#include "conio.h"
#endif

#include <conio.h>
#include <irrlicht.h>
#include "driverChoice.h"
#include <irrKlang.h>
#include <stdio.h>

using namespace irrklang;
using namespace irr;

int move()
{
	if(receiver.IsKeyDown(irr::KEY_KEY_Z))
		{
			nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
			mario->setRotation(irr::core::vector3df(0,270,0));

			chckrot=1;
			check_move = 1;
		}


		if(receiver.IsKeyDown(KEY_KEY_S))
		{
			nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
			mario->setRotation(irr::core::vector3df(0,90,0));
			chckrot=2;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_Q))
		{
			nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
			mario->setRotation(irr::core::vector3df(0,180,0));
			chckrot=3;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_D))
		{
			nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
			mario->setRotation(irr::core::vector3df(0,0,0));
			chckrot=4;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_D)&&receiver.IsKeyDown(KEY_KEY_Z))
		{
			mario->setRotation(irr::core::vector3df(0,315,0));
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_D)&&receiver.IsKeyDown(KEY_KEY_S))
		{
			mario->setRotation(irr::core::vector3df(0,45,0));
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_S)&&receiver.IsKeyDown(KEY_KEY_Q))
		{
			mario->setRotation(irr::core::vector3df(0,135,0));
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_Q)&&receiver.IsKeyDown(KEY_KEY_Z))
		{
			mario->setRotation(irr::core::vector3df(0,225,0));
			check_move = 1;
		}

}