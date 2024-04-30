
#pragma once


template<class T>
struct Vector2
{
	T x{};
	T y{};

	Vector2() = default;
	Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};