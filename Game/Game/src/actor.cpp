
#include "actor.h"


Vector2<int> Actor::getPosition()
{
	return this->position;
}


Vector2<int> Actor::getDirection()
{
	return this->direction;
}


void Actor::setPosition(int _x, int _y)
{
	this->position.x = _x;
	this->position.y = _y;
}


void Actor::setPosition(Vector2<int> _position)
{
	this->position.x = _position.x;
	this->position.y = _position.y;
}


void Actor::moveTo(Vector2<int> _direction)
{
	this->position = this->position + _direction;
}


void Actor::display()
{
	glColor3f(1.0f, 0.0f, 0.0f);

	int block_size = Settings::getBlockSize();

	glBegin(GL_QUADS);
	glVertex2i(this->position.x * block_size, this->position.y * block_size);
	glVertex2i(this->position.x * block_size, (this->position.y + 1) * block_size);
	glVertex2i((this->position.x + 1) * block_size, (this->position.y + 1) * block_size);
	glVertex2i((this->position.x + 1) * block_size, this->position.y * block_size);
	glEnd();
}