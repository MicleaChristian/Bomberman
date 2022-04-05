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
int check_move = 0;

int main(int argc, const char** argv)

{
	ISoundEngine* engine = createIrrKlangDevice();

	video::E_DRIVER_TYPE driverType=driverChoiceConsole();
	if (driverType==video::EDT_COUNT)
		return 1;

	MyEventReceiver receiver;

	IrrlichtDevice* device = createDevice(driverType,
			core::dimension2d<u32>(1920, 1080), 32, false, false, false, &receiver);

	if (device == 0)
		return 1; // could not create selected driver.


	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

	irr::scene::IAnimatedMesh *mesh2 =smgr->getMesh("Assets/mario.b3d");
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

	irr::scene::IAnimatedMeshSceneNode *mario = smgr->addAnimatedMeshSceneNode ( mesh2 );
	if (mario)
	{
		mario->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		mario->setMaterialTexture(0, driver->getTexture("Assets/mario.png"));
		mario->setMaterialTexture(2, driver->getTexture("Assets/meye.png"));
		mario->setMaterialTexture(1, driver->getTexture("Assets/brow.png"));
		mario->setScale(irr::core::vector3df(0.05f, 0.05f, 0.05f));
		mario->setFrameLoop(0,45);
	}

	irr::scene::IAnimatedMeshSceneNode *gr = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr)
	{
		gr->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr->setMaterialTexture(0, driver->getTexture("Assets/brick.png"));
		gr->setPosition(irr::core::vector3df(0,-1.7,0));
		gr->setScale(irr::core::vector3df(0.5f, 0.5f, 0.5f));
	}

	smgr->addCameraSceneNode(0, irr::core::vector3df(-3,2,0), irr::core::vector3df(10, -3, 0));
	device->getCursorControl()->setVisible(false);
	
	int lastFPS = -1;
	u32 then = device->getTimer()->getTime();
	const f32 MOVEMENT_SPEED = 7.f;
	
	engine->play2D("Sounds/mario.ogg", true);

	while(device->run())
	{
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f;
		then = now;



		if(check_move==1)
		{
			mario->setAnimationSpeed(80.0f);
		}
		
		else if(check_move==0)
		{
			mario->setCurrentFrame(10.0f);
			mario->setAnimationSpeed(0.0f);
		}

		core::vector3df nodePosition = mario->getPosition();

		if(receiver.IsKeyDown(irr::KEY_KEY_Z))
		{
			nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
			chckrot=1;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_S))
		{
			nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
			chckrot=2;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_Q))
		{
			nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
			chckrot=3;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_D))
		{
			nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
			chckrot=4;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_D)&&receiver.IsKeyDown(KEY_KEY_Z))
		{
			chckrot=5;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_D)&&receiver.IsKeyDown(KEY_KEY_S))
		{
			chckrot=6;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_S)&&receiver.IsKeyDown(KEY_KEY_Q))
		{
			chckrot=7;
			check_move = 1;
		}

		if(receiver.IsKeyDown(KEY_KEY_Q)&&receiver.IsKeyDown(KEY_KEY_Z))
		{
			chckrot=8;
			check_move = 1;
		}

		if(MOVEMENT_SPEED==0)
			check_move = 0;
			
		if(receiver.IsKeyDown(KEY_SPACE))
		{
			engine->play2D("Sounds/mama.ogg");
		}

		if(!receiver.IsKeyDown(KEY_SPACE))
		{
			if(chckrot==1)
			mario->setRotation(irr::core::vector3df(0,270,0));
			else if(chckrot==2)
			mario->setRotation(irr::core::vector3df(0,90,0));
			if(chckrot==3)
			mario->setRotation(irr::core::vector3df(0,180,0));
			else if(chckrot==4)
			mario->setRotation(irr::core::vector3df(0,0,0));
			if(chckrot==5)
			mario->setRotation(irr::core::vector3df(0,315,0));
			if(chckrot==6)
			mario->setRotation(irr::core::vector3df(0,45,0));
			if(chckrot==7)
			mario->setRotation(irr::core::vector3df(0,135,0));
			if(chckrot==8)
			mario->setRotation(irr::core::vector3df(0,225,0));
		}		

		if(!receiver.IsKeyDown(KEY_KEY_Z)&&!receiver.IsKeyDown(KEY_KEY_Q)&&!receiver.IsKeyDown(KEY_KEY_S)&&!receiver.IsKeyDown(KEY_KEY_D))
		{
			check_move=0;
		}

		mario->setPosition(nodePosition);
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
