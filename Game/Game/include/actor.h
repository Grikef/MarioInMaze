
#pragma once
#include <string>
#include <gl/freeglut.h>
#include "vector2.h"
#include "direction.h"
#include "settings.h"


class Actor
{
protected:
	Vector2<int> position{ 1, 1 };
	Vector2<int> direction{ 0, 0 };

public:
	Actor() = default;
	~Actor() = default;

	Vector2<int> getPosition();

	int getDirection();

	void setPosition(int, int);

	void moveTo(Direction);

	void display();
};