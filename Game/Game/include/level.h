
#pragma once
#include <GL/freeglut.h>
#include "vector2.h"
#include "matrix.h"
#include "settings.h"
#include "textures.h"


class Level
{
private:
	Matrix origin_map{};
	Matrix current_map{ origin_map };

public:
	Level() = default;
	~Level() = default;

	int getValue(int, int);
	int getValue(Vector2<int>);
	int getSize();
	void setValue(int, int, int);
	void SetMap(Matrix);
	void Reset();
	void display();
};