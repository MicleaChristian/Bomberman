/** Example 004 Movement

This Tutorial shows how to move and animate SceneNodes. The
basic concept of SceneNodeAnimators is shown as well as manual
movement of nodes using the keyboard.  We'll demonstrate framerate
independent movement, which means moving by an amount dependent
on the duration of the last run of the Irrlicht loop.

Example 19.MouseAndJoystick shows how to handle those kinds of input.

As always, I include the header files, use the irr namespace,
and tell the linker to link with the .lib file.
*/
#ifdef _MSC_VER
// We'll also define this to stop MSVC complaining about sprintf().
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;

/*
To receive events like mouse and keyboard input, or GUI events like "the OK
button has been clicked", we need an object which is derived from the
irr::IEventReceiver object. There is only one method to override:
irr::IEventReceiver::OnEvent(). This method will be called by the engine once
when an event happens. What we really want to know is whether a key is being
held down, and so we will remember the current state of each key.
*/
class MyEventReceiver : public IEventReceiver
{
public:
	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent& event)
	{
		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

		return false;
	}

	// This is used to check whether a key is being held down
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
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};


int main()
{
	// ask user for driver
	video::E_DRIVER_TYPE driverType=driverChoiceConsole();
	if (driverType==video::EDT_COUNT)
		return 1;

	// create device
	MyEventReceiver receiver;

	IrrlichtDevice* device = createDevice(driverType,
			core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);

	if (device == 0)
		return 1; // could not create selected driver.

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

		
	irr::scene::IAnimatedMesh *mesh2 =smgr->getMesh("Assets/mario.obj");

	if(!mesh2)
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

	
	smgr->addCameraSceneNode(0, irr::core::vector3df(-3,2,0), irr::core::vector3df(10, -3, 0));
	device->getCursorControl()->setVisible(false);

	
	device->getGUIEnvironment()->addImage(
		driver->getTexture("Assets/irrlichtlogoalpha2.tga"),
		core::position2d<s32>(10,20));

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
			nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
		else if(receiver.IsKeyDown(irr::KEY_KEY_S))
			nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;

		if(receiver.IsKeyDown(irr::KEY_KEY_Q))
			nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
		else if(receiver.IsKeyDown(irr::KEY_KEY_D))
			nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;

		node2->setPosition(nodePosition);
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
