#ifndef EVENT_HPP_
#define EVENT_HPP_


#include <conio.h>
#include <irrlicht.h>
#include "driverChoice.h"
#include <irrKlang.h>
#include <stdio.h>

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

#endif /* !EVENT_HPP_ */
