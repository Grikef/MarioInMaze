
#pragma once
#include "player.h"
#include "level.h"


class MoveArbiter
{
private:
	static MoveArbiter* arbiter;
	Player* player;
	Level* level;

	MoveArbiter() = default;
	MoveArbiter(MoveArbiter&) = delete;

	int whenWall();
	int whenTeleport();
	int whenKey(int _key, Vector2<int> _pos);
	int whenDoor(int _door, Vector2<int> _pos);

public:
	static MoveArbiter* getInstance();

	void setPlayer(Player* _player);
	void setLevel(Level* _level);

	void goTo(Vector2<int> _direction);
};