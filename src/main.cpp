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
#include "../include/mario.hpp"


using namespace irrklang;
using namespace irr;
using namespace core;
using namespace scene;
using namespace io;
using namespace std;
using namespace gui;
using namespace video;


int main(int argc, const char** argv)

{

//Variables

	int chckrot=0;
	int check_move = 0;
	int bombe = 0;
	bool soundPlayed = false;
	float f,g,h;
	bool rotation = true;
	bool game = false;
	int m;
	int music = 1;
	int check_menu = 1;
	int check_quit;
	bool sound = false;
	bool sound1 = false;
	bool sound2 = false;
	bool sound3 = false;
	bool sound4 = false;
	bool sound5 = false;
	bool sound6 = false;

//Create sound engine

	ISoundEngine* engine = createIrrKlangDevice();

//Create window

	MyEventReceiver receiver;

	IrrlichtDevice* device = createDevice(video::EDT_OPENGL,core::dimension2d<u32>(1920, 1080), 32, false, false, false, &receiver);

	if (device == 0)
		return 1; // could not create selected driver.


	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

//Load all 3d models

	scene::IAnimatedMesh *mesh2 =smgr->getMesh("../models/mario.b3d");
	scene::IAnimatedMesh *mesh3 =smgr->getMesh("../models/bombe.obj");

//Failure to load 3d models conditions

	if(!mesh2)
	{
		device->drop();
		return 1;
	}

	if(!mesh3)
	{
		device->drop();
		return 1;
	}

//3d models attributes

	IAnimatedMeshSceneNode *mario = smgr->addAnimatedMeshSceneNode ( mesh2 );
	if (mario)
	{
		mario->setMaterialFlag(EMF_LIGHTING, false);
		mario->setMaterialTexture(0, driver->getTexture("../textures/mario.png"));
		mario->setScale(vector3df(0.04f, 0.04f, 0.04f));
		mario->setFrameLoop(0,60);
		mario->setPosition(vector3df(1,-0.5,6));
	}

	IAnimatedMeshSceneNode *bomb = smgr->addAnimatedMeshSceneNode ( mesh3 );
	if (bomb)
	{
		bomb->setMaterialFlag(EMF_LIGHTING, false);
		bomb->setMaterialTexture(0, driver->getTexture("../textures/bomb.png"));
		bomb->setScale(vector3df(0.15f, 0.15f, 0.15f));
		bomb->setPosition(vector3df(5.0,-3,0));
	}

	driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);

//Map gen

	int b;
	int i=0;
	int ii=0;
	int iii=0;
	float x,z =-7.0f;
	float xx,zz =-7.0f;
	float xxx,zzz =-7.0f;
	float y =0.0f;
	float yy =-1.0f;
	int count=0;
	int count1=0;
	int count2=0;

	ITexture *ground;
	ground= driver->getTexture("../textures/brick.png");

	ITexture *gray;
	gray= driver->getTexture("../textures/gray.png");

	ITexture *br;
	br= driver->getTexture("../textures/break.png");

	IMeshSceneNode* gr[b];
	while(i<=14)
	{
		while (count<=14)
		{
			if(i<1)
			{
				gr[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				gr[b]-> setMaterialTexture(0,gray);
				gr[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				gr[b]->setPosition(vector3df(x,y,z));
				gr[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}
			if(i>13)
			{
				gr[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				gr[b]-> setMaterialTexture(0,gray);
				gr[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				gr[b]->setPosition(vector3df(x,y,z));
				gr[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}
			if(count<1)
			{
				gr[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				gr[b]-> setMaterialTexture(0,gray);
				gr[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				gr[b]->setPosition(vector3df(x,y,z));
				gr[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}
			if(count>13)
			{
				gr[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				gr[b]-> setMaterialTexture(0,gray);
				gr[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				gr[b]->setPosition(vector3df(x,y,z));
				gr[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}
		x=x+1;
		count++;
		}
	z=z+1;
	x=0;
	i++;
	count=0;
	}

	IMeshSceneNode* gro[b];
	while(ii<=14)
	{
		while (count1<=14)
		{
		gro[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
		gro[b]-> setMaterialTexture(0,ground);
		gro[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
		gro[b]->setPosition(vector3df(xx,yy,zz));
		gro[b]->setMaterialFlag(video::EMF_LIGHTING, false);
		xx=xx+1;
		count1++;
		}
	zz=zz+1;
	xx=0;
	ii++;
	count1=0;
	}

	IMeshSceneNode* bre[b];
	while(iii<=14)
	{
		while (count2<=14)
		{
			if(xxx==2&&zzz==5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==2&&zzz==3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==2&&zzz==1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==2&&zzz==-1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==2&&zzz==-3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==2&&zzz==-5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

						if(xxx==4&&zzz==5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==4&&zzz==3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==4&&zzz==1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==4&&zzz==-1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==4&&zzz==-3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==4&&zzz==-5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			if(xxx==6&&zzz==5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==6&&zzz==3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==6&&zzz==1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==6&&zzz==-1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==6&&zzz==-3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==6&&zzz==-5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			if(xxx==8&&zzz==5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==8&&zzz==3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==8&&zzz==1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==8&&zzz==-1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==8&&zzz==-3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==8&&zzz==-5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			if(xxx==10&&zzz==5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==10&&zzz==3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==10&&zzz==1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==10&&zzz==-1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==10&&zzz==-3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==10&&zzz==-5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			if(xxx==12&&zzz==5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==12&&zzz==3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==12&&zzz==1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==12&&zzz==-1)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==12&&zzz==-3)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

			else if(xxx==12&&zzz==-5)
			{
				bre[b]= smgr->addCubeSceneNode(1,0,-1, vector3df(0,0,0));
				bre[b]-> setMaterialTexture(0,br);
				bre[b]-> setScale(core::vector3df(1.0f, 1.0f, 1.0f));
				bre[b]->setPosition(vector3df(xxx,y,zzz));
				bre[b]->setMaterialFlag(video::EMF_LIGHTING, false);
			}

		xxx=xxx+1;
		count2++;
		}

	zzz=zzz+1;
	xxx=0;
	iii++;
	count2=0;
	
	}

//Create in-game camera

	smgr->addCameraSceneNode(0, core::vector3df(1,11,0), core::vector3df(10, -15, 0));
	device->getCursorControl()->setVisible(true);

//Create movement physics

	int lastFPS = -1;
	u32 then = device->getTimer()->getTime();
	const f32 MOVEMENT_SPEED = 7.0f;

//Create skydome

    scene::ISceneNode* skydome=smgr->addSkyDomeSceneNode(driver->getTexture("../textures/sky1.png"),32,32,1.0f,2.0f);

	ISceneNodeAnimator* ani=smgr->createRotationAnimator(vector3df(0.009,0.009,0.009));
	skydome->addAnimator(ani);
	ani->drop();
		


    driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);

//Play BGM

	ISoundSource* menu = engine->addSoundSourceFromFile("../sounds/mariomenu.ogg");

	ISoundSource* gmae = engine->addSoundSourceFromFile("../sounds/mario.ogg"); 
	if (music == 1) 
		engine->play2D(menu);

//Open window

	while(device->run())
	{
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f;
		then = now;
		if (rotation == true)

//Menu
	if(game == false)
	{

	if(receiver.IsKeyDown(KEY_KEY_A))
		{
			check_menu = 1;
			if(!sound)
			{
				engine->play2D("../sounds/yoshi.ogg");
				sound=true;
			}
		}


		if(receiver.IsKeyDown(KEY_KEY_Z))
		{
			check_menu = 2;
			if(!sound1)
			{
				engine->play2D("../sounds/yoshi.ogg");
				sound1=true;
			}
		}

		if(receiver.IsKeyDown(KEY_KEY_E))
		{
			check_menu = 11;
			if(!sound2)
			{
				engine->play2D("../sounds/yoshi.ogg");
				sound2=true;
			}
		}

		if(receiver.IsKeyDown(KEY_F1))
		{
			check_menu = 4;
			if(!sound3)
			{
				engine->play2D("../sounds/yoshi.ogg");
				sound3=true;
			}
		}

		if(receiver.IsKeyDown(KEY_F2))
		{
			check_menu = 5;
			if(!sound4)
			{
				engine->play2D("../sounds/yoshi.ogg");
				sound4=true;
			}
		}

		if(receiver.IsKeyDown(KEY_F3))
		{
			check_menu = 6;
			if(!sound5)
			{
				engine->play2D("../sounds/yoshi.ogg");
				sound5=true;
			}
		}

		if(receiver.IsKeyDown(KEY_F4))
		{
			check_menu = 7;
			if(!sound6)
			{
				engine->play2D("../sounds/yoshi.ogg");
				sound6=true;
			}
		}

		if(!receiver.IsKeyDown(KEY_KEY_A))
		sound=false;

		if(!receiver.IsKeyDown(KEY_KEY_Z))
		sound1=false;

		if(!receiver.IsKeyDown(KEY_KEY_E))
		sound2=false;

		if(!receiver.IsKeyDown(KEY_F1))
		sound3=false;

		if(!receiver.IsKeyDown(KEY_F2))
		sound4=false;

		if(!receiver.IsKeyDown(KEY_F3))
		sound5=false;

		if(!receiver.IsKeyDown(KEY_F4))
		sound6=false;


		//std::cout << "check_menu = " << check_menu << std::endl;

		/* std::cout << "check_menu = " << check_menu << std::endl;
		std::cout << "music = " << music << std::endl; */

	//----------------------------conditions----------------------------

		
		if (check_menu == 1 )
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/1-1.png"),
			core::position2d<s32>(-60,0));
		}


		if (check_menu == 2)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/1-2 MARIO MENU OPTIONS S.png"),
			core::position2d<s32>(-60,0));
		}
  
		if (check_menu == 3)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/1-3 MARIO MENU EXIT S.png"),
			core::position2d<s32>(-60,0));	
		}

		if (check_menu == 4)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/2-4-1 MARIO MENU OPTIONS MUSIQUE S.png"),
			core::position2d<s32>(-60,0));	
		}

		if (check_menu == 5)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/2-4-2 MARIO MENU OPTIONS REGLES S.png"),
			core::position2d<s32>(-60,0));	
		}

		if (check_menu == 6)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/2-4-3 MARIO MENU OPTIONS CREDITS S.png"),
			core::position2d<s32>(-60,0));	
		}

		if (check_menu == 7)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/2-4-4 MARIO MENU OPTIONS RETOUR S.png"),
			core::position2d<s32>(-60,0));	
		}

		if (check_menu == 8)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/2-4-2-1 MARIO MENU OPTIONS REGLES S.png"),
			core::position2d<s32>(-60,0));	
		}

		if (check_menu == 9)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/2-4-3-1 MARIO MENU OPTIONS CREDITS S.png"),
			core::position2d<s32>(-60,0));	
		}

		if (check_menu == 10)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/off.png"),
			core::position2d<s32>(-60,0));
		}

		if (check_menu == 11)
		{
			guienv->clear();
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/quit.png"),
			core::position2d<s32>(-60,0));
		}

		if (check_menu == 1 && receiver.IsKeyDown(KEY_RETURN))
		{
			game = true;
			engine->stopAllSounds();
			if (music == 1)
			engine->play2D(gmae);

		}

		if (check_menu == 2 && receiver.IsKeyDown(KEY_RETURN))
		{
			check_menu = 4;
		}

		if (check_menu == 3 && receiver.IsKeyDown(KEY_RETURN))
		{
			return EXIT_SUCCESS;	
		}

		if (check_menu == 5 && receiver.IsKeyDown(KEY_RETURN))
		{
			check_menu = 8;
		}

		if (check_menu == 6 && receiver.IsKeyDown(KEY_RETURN))
		{
			check_menu = 9;
		}

		if (check_menu == 7 && receiver.IsKeyDown(KEY_RETURN))
		{
			check_menu = 1;
		}

		if (check_menu == 4 && receiver.IsKeyDown(KEY_KEY_N))
		{
			check_menu = 10;
			engine->stopAllSounds();
			music = 0;
		}

		if (check_menu == 10 && receiver.IsKeyDown(KEY_KEY_Y))
		{
			check_menu = 4;
			engine->play2D(menu);
			music = 1;
		}

		if (receiver.IsKeyDown(KEY_KEY_E))
		{
			check_menu = 11;
			engine->stopAllSounds();
			engine->play2D("../sounds/no.ogg",true);

		}

		if (check_menu == 11 && receiver.IsKeyDown(KEY_KEY_Y))
		{
			return 0;
		}

		if (check_menu == 11 && receiver.IsKeyDown(KEY_KEY_N))
		{
			check_menu = 1;
			engine->stopAllSounds();
			engine->play2D(menu);
		}
	}
		
//Game

	if (game == true)
	{
		guienv->clear();

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

		if(receiver.IsKeyDown(KEY_KEY_Z))
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
			


		if(!receiver.IsKeyDown(KEY_SPACE))
		{
			if(chckrot==1)
			mario->setRotation(core::vector3df(0,270,0));
			else if(chckrot==2)
			mario->setRotation(core::vector3df(0,90,0));
			if(chckrot==3)
			mario->setRotation(core::vector3df(0,180,0));
			else if(chckrot==4)
			mario->setRotation(core::vector3df(0,0,0));
			if(chckrot==5)
			mario->setRotation(core::vector3df(0,315,0));
			if(chckrot==6)
			mario->setRotation(core::vector3df(0,45,0));
			if(chckrot==7)
			mario->setRotation(core::vector3df(0,135,0));
			if(chckrot==8)
			mario->setRotation(core::vector3df(0,225,0));
			soundPlayed = false;
			
		}		

		if(!receiver.IsKeyDown(KEY_KEY_Z)&&!receiver.IsKeyDown(KEY_KEY_Q)&&!receiver.IsKeyDown(KEY_KEY_S)&&!receiver.IsKeyDown(KEY_KEY_D)&&!receiver.IsKeyDown(KEY_SPACE))
		{
			check_move=0;
			mario->setFrameLoop(0,60);
			mario->setCurrentFrame(61.0f);
		}

		mario->setPosition(nodePosition);

	//Conditions bomb

		if(receiver.IsKeyDown(KEY_SPACE)&& check_move==0)
		{
			mario->setFrameLoop(78,79);
			if(chckrot==1)
			{
				bomb->setPosition(mario->getPosition()+vector3df(1,0,0));
				bomb->setRotation(vector3df(0,180,0));
			}

			else if(chckrot==2)
			{
				bomb->setPosition(mario->getPosition()+vector3df(-1,0,0));
				bomb->setRotation(vector3df(0,0,0));
			}

			if(chckrot==3)
			{
				bomb->setPosition(mario->getPosition()+vector3df(0,0,1));
				bomb->setRotation(vector3df(0,90,0));
			}

			else if(chckrot==4)
			{
				bomb->setPosition(mario->getPosition()+vector3df(0,0,-1));
				bomb->setRotation(vector3df(0,270,0));			
			}

			if (!soundPlayed)
			{
  				engine->play2D("../sounds/run.ogg");
  				soundPlayed = true;
			}

		}

	//Creation collisions

		core::vector3df pos = core::vector3df();
		
 		pos = (*mario).getPosition();

		if(mario->getPosition()>vector3df(13,pos.Y,pos.Z))
			mario->setPosition(vector3df(13,pos.Y,pos.Z));

		if(mario->getPosition()<vector3df(1,pos.Y,pos.Z))
			mario->setPosition(vector3df(1,pos.Y,pos.Z));

		core::vector3df posi = core::vector3df();
		
 		posi = (*mario).getPosition();

		if(mario->getPosition()>vector3df(posi.X,posi.Y,6))
			mario->setPosition(vector3df(posi.X,posi.Y,6));

		if(mario->getPosition()<vector3df(posi.X,posi.Y,-6))
			mario->setPosition(vector3df(posi.X,posi.Y,-6));

//Quit the game

		if (receiver.IsKeyDown(KEY_ESCAPE))
		{
			engine->stopAllSounds();
			engine->play2D("../sounds/no.ogg", true);
			check_menu = 11;
		}


		if (check_menu == 11)
		{
			device->getGUIEnvironment()->addImage(
			driver->getTexture("../textures/quit.png"),
			core::position2d<s32>(-60,0));
			device->getGUIEnvironment()->drawAll(); 
		}

		if (check_menu == 11 && receiver.IsKeyDown(KEY_KEY_Y))
		{
			return 0;
		}

		if (check_menu == 11 && receiver.IsKeyDown(KEY_KEY_N))
		{
			check_menu = 12;
			guienv->clear();
			engine->stopAllSounds();
			engine->play2D(gmae);
		}

	}
			
//Random conditions

		driver->beginScene(true, true, video::SColor(255,0,0,0));

		smgr->drawAll(); // draw the 3d scene
		device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

		driver->endScene();

		int fps = driver->getFPS();

		if (lastFPS != fps)
		{
			core::stringw tmp(L"Super Bomberman");
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