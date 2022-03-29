#include <stdio.h>
#include <irrKlang.h>

#if defined(WIN32)
#include <conio.h>
#else
#include "conio.h"
#endif


using namespace irrklang;


#pragma comment(lib, "irrKlang.lib")


int son(int argc, const char** argv)
{

	ISoundEngine* engine = createIrrKlangDevice();

	if (!engine)
	{
		printf("Could not startup engine\n");
		return 0;
	}

	engine->play2D("Assets/mario.mp3", true);
	engine->drop();
	return 0;
}
