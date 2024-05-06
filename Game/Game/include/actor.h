
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
	Vector2<int> direction{ Direction::RIGHT };

public:
	Actor() = default;
	~Actor() = default;

	Vector2<int> getPosition();

	Vector2<int> getDirection();

	void setPosition(int, int);

	void setPosition(Vector2<int>);

	void moveTo(Vector2<int>);

	void display();
};