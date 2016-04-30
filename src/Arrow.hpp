#ifndef DQ_ARROW_HPP_INCLUDED
#define DQ_ARROW_HPP_INCLUDED

#include <SFML/Graphics/Sprite.hpp>

#include "jam-engine/Core/Entity.hpp"

namespace dq
{

class Arrow : public je::Entity
{
public:
	Arrow(je::Level *level, const sf::Vector2f& pos, const sf::Vector2f& veloc);


private:
	void draw(sf::RenderTarget& target, const sf::RenderStates &states) const override;

	void onUpdate() override;


	sf::Sprite sprite;
	sf::Vector2f veloc;
};

} // dq

#endif // DQ_ARROW_HPP_INCLUDED
