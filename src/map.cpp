#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "irrKlang.lib")
#endif

#include <irrlicht.h>
#include "../include/mario.hpp"

using namespace irr;
	
int map()
{

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

	irr::scene::IAnimatedMesh *mesh =smgr->getMesh("../models/brick.obj");

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

		if(!mesh)
	{
		device->drop();
		return 1;
	}
}