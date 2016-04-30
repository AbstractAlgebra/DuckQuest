#include "Arrow.hpp"

#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Core/Level.hpp"
#include "jam-engine/Utility/Trig.hpp"

namespace dq
{

Arrow::Arrow(je::Level *level, const sf::Vector2f& pos, const sf::Vector2f& veloc)
	:je::Entity(level, "Arrow", pos, sf::Vector2i(8, 8), sf::Vector2i(-4, -4))
	,veloc(veloc)
{
	sprite.setTexture(level->getGame().getTexManager().get("arrow.png"));
	sprite.setOrigin(28, 4);
	sprite.setPosition(pos);
	sprite.setRotation(-je::direction(veloc));
}

void Arrow::draw(sf::RenderTarget& target, const sf::RenderStates &states) const
{
	target.draw(sprite, states);
}

void Arrow::onUpdate()
{
	veloc *= 0.95f;
	if (je::length(veloc) <= 1.f)
	{
		destroy();
	}
	transform().move(veloc);
	sprite.setPosition(getPos());
	sprite.setRotation(-je::direction(veloc));
}

} // dq
