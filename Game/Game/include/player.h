
#pragma once
#include <string>
#include "actor.h"
#include "backpack.h"


class Player : public Actor
{
private:
	Direction direction{ Direction::RIGHT };
	Direction directionToDraw{ Direction::RIGHT };
	Backpack* backpakc = new Backpack();

public:
	Player() = default;
	~Player() = default;

	void addToBackpack(Texture::TextureName);

	bool isInBackpack(Texture::TextureName);

	void removeFromBackpack(Texture::TextureName);

	void clearBackpack();

	Direction getDirection();

	void moveTo(Direction _direction);

	void display(int);
};