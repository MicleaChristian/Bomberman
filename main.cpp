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

class MyEventReceiver : public IEventReceiver
{

public:
	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent& event)
	
	{

		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

		return false;

	}

	virtual bool IsKeyDown(EKEY_CODE keyCode) const

	{
	
		return KeyIsDown[keyCode];
	
	}
	
	MyEventReceiver()
	
	{

		for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	
	}

private:

	bool KeyIsDown[KEY_KEY_CODES_COUNT];

};

int chckrot=0;

int main(int argc, const char** argv)

{

	// ask user for driver
	video::E_DRIVER_TYPE driverType=driverChoiceConsole();
	if (driverType==video::EDT_COUNT)
		return 1;

	// create device
	MyEventReceiver receiver;

	IrrlichtDevice* device = createDevice(driverType,
			core::dimension2d<u32>(1920, 1080), 32, false, false, false, &receiver);

	if (device == 0)
		return 1; // could not create selected driver.

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

		
	irr::scene::IAnimatedMesh *mesh2 =smgr->getMesh("Assets/mario.obj");
	irr::scene::IAnimatedMesh *mesh =smgr->getMesh("Assets/brick.obj");

	if(!mesh2)
	{
		device->drop();
		return 1;
	}

	if(!mesh)
	{
		device->drop();
		return 1;
	}

	irr::scene::IAnimatedMeshSceneNode *node2 = smgr->addAnimatedMeshSceneNode ( mesh2 );
	if (node2)
	{
		node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node2->setMaterialTexture(0, driver->getTexture("Assets/mario.jpg"));
	}

	irr::scene::IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode ( mesh );
	if (node)
	{
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setMaterialTexture(0, driver->getTexture("Assets/brick.png"));
	}
		node->setScale(irr::core::vector3df(0.5f, 0.5f, 0.5f));
	


	smgr->addCameraSceneNode(0, irr::core::vector3df(-3,2,0), irr::core::vector3df(10, -3, 0));
	device->getCursorControl()->setVisible(false);

	gui::IGUIStaticText* diagnostics = device->getGUIEnvironment()->addStaticText(
		L"", core::rect<s32>(10, 10, 400, 20));
	diagnostics->setOverrideColor(video::SColor(255, 255, 255, 0));


	
	int lastFPS = -1;

	u32 then = device->getTimer()->getTime();

	// This is the movemen speed in units per second.
	const f32 MOVEMENT_SPEED = 5.f;

	while(device->run())
	{

		// Work out a frame delta time.
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;

		/* Check if keys W, S, A or D are being held down, and move the
		sphere node around respectively. */
		core::vector3df nodePosition = node2->getPosition();

		if(receiver.IsKeyDown(irr::KEY_KEY_Z))
		{
			nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
			node2->setRotation(irr::core::vector3df(0,360,0));
			chckrot=1;
		}

		else if(receiver.IsKeyDown(irr::KEY_KEY_S))
		{
			nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
			node2->setRotation(irr::core::vector3df(0,180,0));
			chckrot=2;
		}

		if(receiver.IsKeyDown(irr::KEY_KEY_Q))
		{
			nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
			node2->setRotation(irr::core::vector3df(0,270,0));
			chckrot=3;
		}

		else if(receiver.IsKeyDown(irr::KEY_KEY_D))
		{
			nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
			node2->setRotation(irr::core::vector3df(0,90,0));
			chckrot=4;
		}

		if(receiver.IsKeyDown(irr::KEY_KEY_D)&&receiver.IsKeyDown(irr::KEY_KEY_Z))
		{
			node2->setRotation(irr::core::vector3df(0,45,0));
		}

		if(receiver.IsKeyDown(irr::KEY_KEY_D)&&receiver.IsKeyDown(irr::KEY_KEY_S))
		{
			node2->setRotation(irr::core::vector3df(0,135,0));
		}

		if(receiver.IsKeyDown(irr::KEY_KEY_S)&&receiver.IsKeyDown(irr::KEY_KEY_Q))
		{
			node2->setRotation(irr::core::vector3df(0,225,0));
		}

		if(receiver.IsKeyDown(irr::KEY_KEY_Q)&&receiver.IsKeyDown(irr::KEY_KEY_Z))
		{
			node2->setRotation(irr::core::vector3df(0,315,0));
		}

		if(receiver.IsKeyDown(irr::KEY_SPACE))
		{
			if(chckrot==1)
			node2->setRotation(irr::core::vector3df(0,360,-90));
			else if(chckrot==2)
			node2->setRotation(irr::core::vector3df(0,180,90));
			if(chckrot==3)
			node2->setRotation(irr::core::vector3df(-90,270,0));
			else if(chckrot==4)
			node2->setRotation(irr::core::vector3df(90,90,0));
		}


		node2->setPosition(nodePosition);
		driver->beginScene(true, true, video::SColor(255,0,255,255));

		smgr->drawAll(); // draw the 3d scene
		device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

		driver->endScene();

		int fps = driver->getFPS();

		if (lastFPS != fps)
		{
			core::stringw tmp(L"Supew Bombewman");
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
