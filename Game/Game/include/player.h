
#pragma once
#include <string>
#include "actor.h"
#include "backpack.h"


class Player : public Actor
{
private:
	Vector2<int> direction{ Direction::RIGHT };
	Vector2<int> directionToDraw{ Direction::RIGHT };
	Backpack* backpakc = new Backpack();

public:
	Player() = default;
	~Player() = default;

	void addToBackpack(Texture::TextureName);

	bool isInBackpack(Texture::TextureName);

	void removeFromBackpack(Texture::TextureName);

	void clearBackpack();

	Vector2<int> getDirection();

	void moveTo(Vector2<int>);

	void display(int);
};