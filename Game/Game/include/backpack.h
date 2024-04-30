
#pragma once
#include <set>
#include <string>
#include <GL/freeglut.h>
#include "textures.h"
#include "settings.h"


class Backpack
{
private:
	std::multiset<int> backpack{};

public:
	Backpack() = default;
	~Backpack() = default;

	void addToBackpack(Texture::TextureName);

	bool isInBackpack(Texture::TextureName);

	void removeFromBackpack(Texture::TextureName);

	void clearBackpack();

	void display(int, int);
};