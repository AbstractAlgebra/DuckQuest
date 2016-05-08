#include "Enemy.hpp"

#include "Arrow.hpp"
#include "Dungeon.hpp"

#include "Player.hpp"

#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Core/GamepadPredefs.hpp"
#include "jam-engine/Utility/Assert.hpp"
#include "jam-engine/Utility/Trig.hpp"

namespace dq
{
	Enemy::Enemy(Dungeon& dungeon)
		:je::Entity(&dungeon, "Player", sf::Vector2f(dungeon.getWidth() / 4, dungeon.getHeight() / 4), sf::Vector2i(32, 32), sf::Vector2i(-16, -16))
		, sprite(dungeon.getGame().getTexManager().get("enemy.png"))
		, bBox(sprite.getPosition().x, sprite.getPosition().y,400,400)
		,dungeon(dungeon)

{
	sprite.setOrigin(16, 16);

}

void Enemy::onUpdate()
{
	std::vector<je::Ref<je::Entity>> results;
	dungeon.findCollisions(results, bBox,"Player");

	//TODO: add code to find closest player
	//ACTS LIKE A POINTER
	je::Ref<Player> k = results[0];

	if (k->getPos().x > this->getPos().x) {
		this->transform().setPosition(this->getPos().x+1, this->getPos().y);
	}

	if (k->getPos().x < this->getPos().x) {
		this->transform().setPosition(this->getPos().x - 1, this->getPos().y);
	}

	if (k->getPos().y < this->getPos().y) {
		this->transform().setPosition(this->getPos().x, this->getPos().y - 1);
	}

	if (k->getPos().y > this->getPos().y) {
		this->transform().setPosition(this->getPos().x, this->getPos().y+1);
	}

	sprite.setPosition(getPos());
}

void Enemy::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(sprite, states);
}
}
 // dq
