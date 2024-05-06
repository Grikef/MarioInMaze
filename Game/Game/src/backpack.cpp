
#include "backpack.h"


void Backpack::addToBackpack(Texture::TextureName _item)
{
	this->backpack.insert(_item);
}


bool Backpack::isInBackpack(Texture::TextureName _item)
{
	if (this->backpack.find(_item) != this->backpack.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Backpack::removeFromBackpack(Texture::TextureName _item)
{
	std::multiset<int> ::iterator ptr;
	ptr = this->backpack.find(_item);
	this->backpack.erase(ptr);
}


void Backpack::clearBackpack()
{
	this->backpack.clear();
}


void Backpack::display(int _i, int _j)
{
	int block_size = Settings::getBlockSize();

	glBindTexture(GL_TEXTURE_2D, Texture::TextureName::BACKPACK + 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex2i(block_size * _i, block_size * _j);
	glTexCoord2f(0.0, 0.0);
	glVertex2i(block_size * _i, block_size * (_j + 1));
	glTexCoord2f(1.0, 0.0);
	glVertex2i(block_size * (_i + _j), block_size * (_j + 1));
	glTexCoord2f(1.0, 1.0);
	glVertex2i(block_size * (_i + _j), block_size * _j);
	glEnd();

	std::multiset<int> ::iterator ptr = this->backpack.begin();

	while (ptr != this->backpack.end())
	{
		glBindTexture(GL_TEXTURE_2D, *ptr + 1);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0);
		glVertex2i(block_size * _i, block_size * _j);
		glTexCoord2f(0.0, 0.0);
		glVertex2i(block_size * _i, block_size * (_j + 1));
		glTexCoord2f(1.0, 0.0);
		glVertex2i(block_size * (_i + 1), block_size * (_j + 1));
		glTexCoord2f(1.0, 1.0);
		glVertex2i(block_size * (_i + 1), block_size * _j);
		glEnd();

		_i++;
		ptr++;
	}
}