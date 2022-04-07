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
#include "toto.cpp"
#include "../include/mario.hpp"

using namespace irrklang;
using namespace irr;





//Create variables

int chckrot=0;
int check_move = 0;

int main(int argc, const char** argv)

{

//Create sound engine

	ISoundEngine* engine = createIrrKlangDevice();


//Choose render engine

	int menu();

	video::E_DRIVER_TYPE driverType=driverChoiceConsole();
	if (driverType==video::EDT_COUNT)
		return 1;



//Create window

	MyEventReceiver receiver;

	IrrlichtDevice* device = createDevice(driverType,
			core::dimension2d<u32>(1920, 1080), 32, false, false, false, &receiver);

	if (device == 0)
		return 1; // could not create selected driver.


	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();




//load all 3d models

	irr::scene::IAnimatedMesh *mesh2 =smgr->getMesh("../models/mario.b3d");
	irr::scene::IAnimatedMesh *mesh =smgr->getMesh("../models/brick.obj");


//failure to load 3d models conditions

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


//3d models attributes

	irr::scene::IAnimatedMeshSceneNode *mario = smgr->addAnimatedMeshSceneNode ( mesh2 );
	if (mario)
	{
		mario->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		mario->setMaterialTexture(0, driver->getTexture("../textures/mario.png"));
		mario->setMaterialTexture(2, driver->getTexture("../textures/meye.png"));
		mario->setMaterialTexture(1, driver->getTexture("../textures/brow.png"));
		mario->setScale(irr::core::vector3df(0.05f, 0.05f, 0.05f));
		mario->setFrameLoop(0,60);
	}
//map gen
	irr::scene::IAnimatedMeshSceneNode *gr = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr)
	{
		gr->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr->setPosition(irr::core::vector3df(0,-1.5,0));
		gr->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr1 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr1)
	{
		gr1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr1->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr1->setPosition(irr::core::vector3df(0,-1.5,1.5));
		gr1->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr2 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr2)
	{
		gr2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr2->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr2->setPosition(irr::core::vector3df(0,-1.5,-1.5));
		gr2->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr3 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr3)
	{
		gr3->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr3->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr3->setPosition(irr::core::vector3df(0,-1.5,3));
		gr3->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}


	irr::scene::IAnimatedMeshSceneNode *gr4 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr4)
	{
		gr4->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr4->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr4->setPosition(irr::core::vector3df(0,-1.5,-3));
		gr4->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}


	irr::scene::IAnimatedMeshSceneNode *gr5 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr5)
	{
		gr5->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr5->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr5->setPosition(irr::core::vector3df(1.5,-1.5,0));
		gr5->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr6 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr6)
	{
		gr6->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr6->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr6->setPosition(irr::core::vector3df(1.5,-1.5,1.5));
		gr6->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr7 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr7)
	{
		gr7->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr7->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr7->setPosition(irr::core::vector3df(1.5,-1.5,3));
		gr7->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr8 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr8)
	{
		gr8->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr8->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr8->setPosition(irr::core::vector3df(1.5,-1.5,-1.5));
		gr8->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr9 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr9)
	{
		gr9->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr9->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr9->setPosition(irr::core::vector3df(1.5,-1.5,-3));
		gr9->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}


	irr::scene::IAnimatedMeshSceneNode *gr10 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr10)
	{
		gr10->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr10->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr10->setPosition(irr::core::vector3df(3,-1.5,-3));
		gr10->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr11 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr11)
	{
		gr11->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr11->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr11->setPosition(irr::core::vector3df(4.5,-1.5,-3));
		gr11->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr12 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr12)
	{
		gr12->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr12->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr12->setPosition(irr::core::vector3df(6,-1.5,-3));
		gr12->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

    irr::scene::IAnimatedMeshSceneNode *gr13 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr13)
	{
		gr13->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr13->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr13->setPosition(irr::core::vector3df(4.5,-1.5,-1.5));
		gr13->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr14 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr14)
	{
		gr14->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr14->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr14->setPosition(irr::core::vector3df(3,-1.5,-1.5));
		gr14->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr15 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr15)
	{
		gr15->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr15->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr15->setPosition(irr::core::vector3df(6,-1.5,-1.5));
		gr15->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr16 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr16)
	{
		gr16->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr16->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr16->setPosition(irr::core::vector3df(4.5,-1.5,0));
		gr16->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr17 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr17)
	{
		gr17->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr17->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr17->setPosition(irr::core::vector3df(3,-1.5,0));
		gr17->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr18 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr18)
	{
		gr18->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr18->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr18->setPosition(irr::core::vector3df(6,-1.5,0));
		gr18->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr19 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr19)
	{
		gr19->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr19->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr19->setPosition(irr::core::vector3df(4.5,-1.5,1.5));
		gr19->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr20 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr20)
	{
		gr20->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr20->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr20->setPosition(irr::core::vector3df(3,-1.5,1.5));
		gr20->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr21 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr21)
	{
		gr21->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr21->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr21->setPosition(irr::core::vector3df(6,-1.5,1.5));
		gr21->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr22 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr22)
	{
		gr22->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr22->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr22->setPosition(irr::core::vector3df(4.5,-1.5,3));
		gr22->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr23 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr23)
	{
		gr23->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr23->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr23->setPosition(irr::core::vector3df(3,-1.5,3));
		gr23->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr24 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr24)
	{
		gr24->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr24->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr24->setPosition(irr::core::vector3df(6,-1.5,3));
		gr24->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr25 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr25)
	{
		gr25->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr25->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr25->setPosition(irr::core::vector3df(0,-1.5,4.5));
		gr25->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr26 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr26)
	{
		gr26->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr26->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr26->setPosition(irr::core::vector3df(1.5,-1.5,4.5));
		gr26->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr27 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr27)
	{
		gr27->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr27->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr27->setPosition(irr::core::vector3df(3,-1.5,4.5));
		gr27->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr28 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr28)
	{
		gr28->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr28->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr28->setPosition(irr::core::vector3df(4.5,-1.5,4.5));
		gr28->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr29 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr29)
	{
		gr29->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr29->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr29->setPosition(irr::core::vector3df(6,-1.5,4.5));
		gr29->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

		irr::scene::IAnimatedMeshSceneNode *gr30 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr30)
	{
		gr30->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr30->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr30->setPosition(irr::core::vector3df(0,-1.5,-4.5));
		gr30->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr31 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr31)
	{
		gr31->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr31->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr31->setPosition(irr::core::vector3df(1.5,-1.5,-4.5));
		gr31->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr32 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr32)
	{
		gr32->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr32->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr32->setPosition(irr::core::vector3df(3,-1.5,-4.5));
		gr32->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr33 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr33)
	{
		gr33->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr33->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr33->setPosition(irr::core::vector3df(4.5,-1.5,-4.5));
		gr33->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr34 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr34)
	{
		gr34->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr34->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr34->setPosition(irr::core::vector3df(6,-1.5,-4.5));
		gr34->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr35 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr35)
	{
		gr35->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr35->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr35->setPosition(irr::core::vector3df(7.5,-1.5,-4.5));
		gr35->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr36 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr36)
	{
		gr36->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr36->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr36->setPosition(irr::core::vector3df(7.5,-1.5,4.5));
		gr36->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr37 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr37)
	{
		gr37->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr37->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr37->setPosition(irr::core::vector3df(7.5,-1.5,3));
		gr37->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr38 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr38)
	{
		gr38->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr38->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr38->setPosition(irr::core::vector3df(7.5,-1.5,-3));
		gr38->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr39 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr39)
	{
		gr39->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr39->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr39->setPosition(irr::core::vector3df(7.5,-1.5,1.5));
		gr39->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr40 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr40)
	{
		gr40->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr40->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr40->setPosition(irr::core::vector3df(7.5,-1.5,-1.5));
		gr40->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

	irr::scene::IAnimatedMeshSceneNode *gr41 = smgr->addAnimatedMeshSceneNode ( mesh );
	if (gr41)
	{
		gr41->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		gr41->setMaterialTexture(0, driver->getTexture("../textures/brick.png"));
		gr41->setPosition(irr::core::vector3df(7.5,-1.5,0));
		gr41->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
	}

//Create in-game camera

	smgr->addCameraSceneNode(0, irr::core::vector3df(0,7,0), irr::core::vector3df(9, -15, 0));
	device->getCursorControl()->setVisible(false);
	

//create movement physics

	int lastFPS = -1;
	u32 then = device->getTimer()->getTime();
	const f32 MOVEMENT_SPEED = 7.f;
	

//play BGM

	engine->play2D("../sounds/mario.ogg", true);


//open window

	while(device->run())
	{
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f;
		then = now;



//Movement
		if(check_move==1)
		{
			mario->setAnimationSpeed(90.0f);
		}
		
		else if(check_move==0)
		{
			mario->setCurrentFrame(61.0f);  
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
			
		if(receiver.IsKeyDown(KEY_SPACE)&& check_move==0)
		{
			//engine->play2D("sounds/mama.ogg");
			mario->setFrameLoop(78,79);
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

		if(!receiver.IsKeyDown(KEY_KEY_Z)&&!receiver.IsKeyDown(KEY_KEY_Q)&&!receiver.IsKeyDown(KEY_KEY_S)&&!receiver.IsKeyDown(KEY_KEY_D)&&!receiver.IsKeyDown(KEY_SPACE))
		{
			check_move=0;
			mario->setFrameLoop(0,60);
			mario->setCurrentFrame(61.0f);
		}

		mario->setPosition(nodePosition);




		driver->beginScene(true, true, video::SColor(255,0,0,0));

		smgr->drawAll(); // draw the 3d scene
		device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

		driver->endScene();

		int fps = driver->getFPS();

		if (lastFPS != fps)
		{
			core::stringw tmp(L"Supew Bombeuwman");
			tmp += L"   fps: ";
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