#ifndef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/ssubsystem:windows /ENTRY:mainCRTStartup")
#endif

#include <irrlicht.h>
#include <iostream>
#include "../include/mario.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


//Structure qui stock le contexte du receveur d'event
struct SAppContext
{

  		IrrlichtDevice *device;
  		s32             counter;
  		IGUIListBox*    listbox;


};


int main()
{
	ISoundEngine* engine = createIrrKlangDevice();

	MyEventReceiver receiver;

	 IrrlichtDevice *device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(1900, 1080), 16,
                  false, false, false, &receiver);

	if (device == 0)
		return 1; // could not create selected driver.

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	
	
	
	
	
	int lastFPS = -1;
	u32 then = device->getTimer()->getTime();

	// This is the movemen speed in units per second.
	const f32 MOVEMENT_SPEED = 5.f;
	int i;
	int check_menu = i = 1;
	engine->play2D("../sounds/mariomenu.ogg", true);
	while(device->run())
	{
		// Work out a frame delta time.
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;

		
		if(receiver.IsKeyDown(irr::KEY_DOWN))
		{
			check_menu = check_menu - 1;
			engine->play2D("../sounds/yoshi.ogg", false);
		}
			
		else if(receiver.IsKeyDown(irr::KEY_UP))
		{
			check_menu = check_menu + 1;
			engine->play2D("../sounds/yoshi.ogg", false);
		}

		std::cout << "check_menu = " << check_menu << std::endl;


		
		if (check_menu == 1 )
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/MARIO_MENU_JOUER.png"),
			core::position2d<s32>(-60,0));
		}


		else if (check_menu == 2)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/MARIO_MENU_OPTIONS.png"),
			core::position2d<s32>(-60,0));
		}
  
		else if (check_menu == 3)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/MARIO_MENU_EXIT.png"),
			core::position2d<s32>(-60,0));	
		}

  		if(check_menu >= 4)
			check_menu = 1;

		else if(check_menu <= 0)
			check_menu = 3;
		driver->beginScene(true, true, video::SColor(255,113,113,133));

		smgr->drawAll(); // draw the 3d scene
		device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

		driver->endScene();

		int fps = driver->getFPS();

		if (lastFPS != fps)
		{
			core::stringw tmp(L"Movement Example - Irrlicht Engine [");
			tmp += driver->getName();
			tmp += L"] fps: ";
			tmp += fps;

			device->setWindowCaption(tmp.c_str());
			lastFPS = fps;
		}

	}
	/*
	In the end, delete the Irrlicht device.
	*/
	device->drop();
	
	return 0;
}

/*
That's it. Compile and play around with the program.
**/
