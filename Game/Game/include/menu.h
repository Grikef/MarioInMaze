
#pragma once
#include <gl/freeglut.h>
#include <iostream>
#include "settings.h"
#include "textures.h"


class Menu
{
public:
	/*static GLubyte* hower;
	static GLubyte* unhower;
	static GLubyte* colorPlay;
	static GLubyte* colorLevel;
	static GLubyte* colorQuit;*/

	static void Setup();

	//static void Destroy();

	static void RenderMenu();

	static void ProcessMouse(int, int, int, int);

	static void ProcessMotion(int, int);
};