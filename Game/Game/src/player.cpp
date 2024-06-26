
#include "player.h"


void Player::addToBackpack(Texture::TextureName _item)
{
	this->backpakc->addToBackpack(_item);
}


bool Player::isInBackpack(Texture::TextureName _item)
{
	if (this->backpakc->isInBackpack(_item))
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Player::removeFromBackpack(Texture::TextureName _item)
{
	this->backpakc->removeFromBackpack(_item);
}


void Player::clearBackpack()
{
	this->backpakc->clearBackpack();
}


Vector2<int> Player::getDirection()
{
	return this->direction;
}


void Player::moveTo(Vector2<int> _direction)
{
	this->direction = _direction;
	this->position += _direction;
	
	if (_direction == Direction::RIGHT)
	{
		this->directionToDraw = _direction;
	}

	if (_direction == Direction::LEFT)
	{
		this->directionToDraw = _direction;
	}
}


void Player::display(int _mapSize)
{
	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::PLAYER + 1);
	//glColor3f(1.0f, 0.0f, 0.0f);

	int block_size = Settings::getBlockSize();

	glBegin(GL_QUADS);
	if (this->directionToDraw == Direction::RIGHT)
	{
		glTexCoord2f(0.0, 1.0);
		glVertex2i(this->position.x * block_size, this->position.y * block_size);
		glTexCoord2f(0.0, 0.0);
		glVertex2i(this->position.x * block_size, (this->position.y + 1) * block_size);
		glTexCoord2f(1.0, 0.0);
		glVertex2i((this->position.x + 1) * block_size, (this->position.y + 1) * block_size);
		glTexCoord2f(1.0, 1.0);
		glVertex2i((this->position.x + 1) * block_size, this->position.y * block_size);
	}
	else
	{
		glTexCoord2f(1.0, 1.0);
		glVertex2i(this->position.x * block_size, this->position.y * block_size);
		glTexCoord2f(1.0, 0.0);
		glVertex2i(this->position.x * block_size, (this->position.y + 1) * block_size);
		glTexCoord2f(0.0, 0.0);
		glVertex2i((this->position.x + 1) * block_size, (this->position.y + 1) * block_size);
		glTexCoord2f(0.0, 1.0);
		glVertex2i((this->position.x + 1) * block_size, this->position.y * block_size);
	}
	glEnd();

	backpakc->display(0, _mapSize);
}