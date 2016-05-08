#ifndef DQ_PLAYER_HPP_INCLUDED
#define DQ_PLAYER_HPP_INCLUDED

#include "jam-engine/Core/Entity.hpp"
#include "jam-engine/Core/Controller.hpp"

#include <SFML/Graphics/Sprite.hpp>

namespace dq
{

class Dungeon;

class Player : public je::Entity
{
public:
	Player(Dungeon &dungeon); // @TODO decide what to pass this. Position? Identifier? Controller? Some kind of PlayerConfig?

private:
	void onUpdate() override;
	void killPlayer();

	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
	Dungeon& dungeon;
	sf::Rect<int> bBox;
	je::Controller controls;
	sf::Sprite sprite;
	je::AxesSet movement;
	je::AxesSet aiming;
	//je::AxesSet aiming;
	const int playerID;
};

} // dq

#endif // DQ_PLAYER_HPP_INCLUDED