
#pragma once


template<class T>
struct Vector2
{
	T x{};
	T y{};

	Vector2() = default;
	Vector2(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2<T> operator + (const Vector2<T>& add)
	{
		return Vector2<T>(this->x + add.x, this->y + add.y);
	}

	Vector2<T>& operator += (const Vector2<T>& add)
	{
		this->x += add.x;
		this->y += add.y;
		return *this;
	}

	Vector2<T> operator * (int count)
	{
		return Vector2<T>(this->x * count, this->y * count);
	}

	bool operator == (const Vector2<T>& eq)
	{
		return this->x == eq.x && this->y == eq.y;
	}
};