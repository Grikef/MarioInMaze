
#include "arbiter.h"


MoveArbiter* MoveArbiter::arbiter = nullptr;


MoveArbiter* MoveArbiter::getInstance()
{
	if (arbiter == nullptr)
	{
		arbiter = new MoveArbiter();
		return arbiter;
	}
	else
		return arbiter;
}


void MoveArbiter::setPlayer(Player* _player)
{
	player = _player;
}


void MoveArbiter::setLevel(Level* _level)
{
	level = _level;
}


void MoveArbiter::goTo(Vector2<int> _direction)
{
	if (player == nullptr || level == nullptr)
	{
		return;
	}

	int object = level->getValue(player->getPosition() + _direction);
	int step = 0;

	switch (object)
	{
		case Texture::TextureName::WALL:
		{
			step = whenWall();
			break;
		}

		case Texture::TextureName::TELEPORT:
		{
			step = whenTeleport();
			break;
		}

		case Texture::TextureName::FINISH:
		{
			// Так делать явно плохо, но пока не нашёл другого решения 
			extern void LoadLevel(bool next, int levelNumber = 0);
			LoadLevel(true);
			break;
		}

		case Texture::TextureName::GREEN_KEY:
		case Texture::TextureName::YELLOW_KEY:
		{
			step = whenKey(object, player->getPosition() + _direction);
			break;
		}

		case Texture::TextureName::GREEN_DOOR:
		case Texture::TextureName::YELLOW_DOOR:
		{
			step = whenDoor(object, player->getPosition() + _direction);
			break;
		}

		default:
		{
			step = 1;
		}
	}

	player->moveTo(_direction * step);
}


int MoveArbiter::whenWall()
{
	return 0;
}


int MoveArbiter::whenTeleport()
{
	return 3;
}


int MoveArbiter::whenKey(int _key, Vector2<int> _pos)
{
	Texture::TextureName key =
		_key == Texture::TextureName::YELLOW_KEY ?
		Texture::TextureName::YELLOW_KEY_IN_BACKPACK :
		Texture::TextureName::GREEN_KEY_IN_BACKPACK;

	player->addToBackpack(key);
	level->setValue(_pos, Texture::TextureName::FLOOR);
	return 1;
}


int MoveArbiter::whenDoor(int _door, Vector2<int> _pos)
{
	Texture::TextureName key =
		_door == Texture::TextureName::YELLOW_DOOR ?
		Texture::TextureName::YELLOW_KEY_IN_BACKPACK :
		Texture::TextureName::GREEN_KEY_IN_BACKPACK;

	if (player->isInBackpack(key))
	{
		level->setValue(_pos, Texture::TextureName::FLOOR);
		player->removeFromBackpack(key);
	}

	return 0;
}