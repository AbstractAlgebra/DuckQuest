#include "Dungeon.hpp"

#include "Player.hpp"

namespace dq
{

Dungeon::Dungeon(je::Game *game)
	:je::Level(game, 640, 480) // @todo don't fix size
{
	for (int i = 0; i < 3; ++i)
	{
		addEntity(std::unique_ptr<je::Entity>(new Player(*this)));
	}
}

} // dq
