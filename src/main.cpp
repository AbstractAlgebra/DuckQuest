#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Graphics/TexManager.hpp"

#include "Dungeon.hpp"

int main()
{
	je::Game game(640, 480, 60);
	game.getTexManager().setPath("img/");
	game.setLevel(new dq::Dungeon(&game));
    return game.execute();
}