
#pragma once
#include <SOIL2/SOIL2.h>
#include <GL/freeglut.h>
#include <string>
#include <filesystem>


class Texture
{
private:
	static std::string prefix;

public:
	enum TextureName
	{
		FLOOR = 0,
		WALL = 1,
		FINISH = 2,
		YELLOW_KEY = 3,
		GREEN_KEY = 4,
		PLAYER = 5,
		TELEPORT = 6,
		YELLOW_DOOR = 7,
		GREEN_DOOR = 8,
		YELLOW_KEY_IN_BACKPACK = 9,
		GREEN_KEY_IN_BACKPACK = 10,
		MENU_START = 11,
		MENU_LEVEL = 12,
		MENU_EXIT = 13,
		LEVEL1 = 14,
		LEVEL2 = 15,
		LEVEL3 = 16,
		LEVEL4 = 17,
		LEVEL5 = 18,
		LEVEL6 = 19,
		LEVEL7 = 20,
		LEVEL8 = 21,
		LEVEL9 = 22,
		ENUM_COUNT = 23
	};

	static char* getColor(int);
	static void initTextures();
};