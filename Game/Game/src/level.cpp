
#include "level.h"


int Level::getValue(int _i, int _j)
{
	return this->current_map.getValue(_i, _j);
}


int Level::getValue(Vector2<int> _position)
{
	return this->current_map.getValue(_position.x, _position.y);
}


int Level::getSize()
{
	return this->current_map.getSize();
}


void Level::setValue(int _i, int _j, int _value)
{
	this->current_map.setValue(_i, _j, _value);
}


void Level::setValue(Vector2<int> _position, int _value)
{
	this->current_map.setValue(_position.x, _position.y, _value);
}


void Level::SetMap(Matrix _matrix)
{
	  this->origin_map.setValues(_matrix.getValues(), _matrix.getSize());
	  this->current_map.setValues(_matrix.getValues(), _matrix.getSize());
}


void Level::Reset()
{
	this->current_map.setValues(this->origin_map.getValues(), this->origin_map.getSize());
}


void Level::display()
{
	int block_size = Settings::getBlockSize();

	for (int i{ 0 }; i < current_map.getSize(); i++)
	{
		for (int j{ 0 }; j < current_map.getSize(); j++)
		{
			glBindTexture(GL_TEXTURE_2D, current_map.getValue(i, j) + 1);

			/*GLubyte* color = (GLubyte*)Texture::getColor(current_map.getValue(i, j));
			glColor3ubv( color );
			delete color;*/

			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 1.0);
			glVertex2i(block_size * i, block_size * j);
			glTexCoord2f(0.0, 0.0);
			glVertex2i(block_size * i, block_size * (j + 1));
			glTexCoord2f(1.0, 0.0);
			glVertex2i(block_size * (i + 1), block_size * (j + 1));
			glTexCoord2f(1.0, 1.0);
			glVertex2i(block_size * (i + 1), block_size * j);
			glEnd();
		}
	}
}