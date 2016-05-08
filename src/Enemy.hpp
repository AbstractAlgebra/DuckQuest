#ifndef DQ_ENEMY_HPP_INCLUDED
#define DQ_ENEMY_HPP_INCLUDED

#include "jam-engine/Core/Entity.hpp"
#include "Dungeon.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace dq 
{
class Dungeon;
class Enemy : public je::Entity
{
public:
	Enemy(Dungeon &dungeon); // @TODO decide what to pass this. Position? Identifier? Controller? Some kind of PlayerConfig?

private:
	void onUpdate() override;
	sf::Sprite sprite;
	Dungeon& dungeon;
	sf::Rect<int> bBox;

	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

};

}
#endif // DQ_ENEMY_HPP_INCLUDED