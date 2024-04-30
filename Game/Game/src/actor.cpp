
#include "actor.h"


Vector2<int> Actor::getPosition()
{
	return this->position;
}


int Actor::getDirection()
{
	
}


void Actor::setPosition(int _x, int _y)
{
	this->position.x = _x;
	this->position.y = _y;
}


void Actor::moveTo(Direction _direction)
{
	switch (_direction)
	{
	case Direction::UP:
		{
			this->position.y += 1;
			break;
		}

	case Direction::RIGHT:
		{
			this->position.x += 1;
			break;
		}

	case Direction::DOWN:
		{
			this->position.y -= 1;
			break;
		}

	case Direction::LEFT:
		{
			this->position.x -= 1;
			break;
		}
	}
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