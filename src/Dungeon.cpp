#include "Dungeon.hpp"

#include "Player.hpp"
#include "Enemy.hpp"
namespace dq
{

Dungeon::Dungeon(je::Game *game)
	:je::Level(game, 640, 480) // @todo don't fix size
{
	for (int i = 0; i < 1; ++i)//CHANGE TO 3 FOR 3 PlAYERS
	{
		addEntity(std::unique_ptr<je::Entity>(new Player(*this)));
	}

	addEntity(std::unique_ptr<je::Entity>(new Enemy(*this)));

}

} // dq
