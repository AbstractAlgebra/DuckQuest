#include "Player.hpp"

#include "Arrow.hpp"
#include "Dungeon.hpp"

#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Core/GamepadPredefs.hpp"
#include "jam-engine/Utility/Assert.hpp"
#include "jam-engine/Utility/Trig.hpp"

namespace dq
{

const int maxPlayers = 3;

sf::Keyboard::Key leftKeys[maxPlayers] = {
	sf::Keyboard::Left,
	sf::Keyboard::A,
	sf::Keyboard::J
};

sf::Keyboard::Key rightKeys[maxPlayers] = {
	sf::Keyboard::Right,
	sf::Keyboard::D,
	sf::Keyboard::L
};

sf::Keyboard::Key upKeys[maxPlayers] = {
	sf::Keyboard::Up,
	sf::Keyboard::W,
	sf::Keyboard::I
};

sf::Keyboard::Key downKeys[maxPlayers] = {
	sf::Keyboard::Down,
	sf::Keyboard::S,
	sf::Keyboard::K
};

sf::Keyboard::Key fireKeys[maxPlayers] = {
	sf::Keyboard::RControl,
	sf::Keyboard::X,
	sf::Keyboard::N
};

const sf::Color playerColours[maxPlayers] = {
	sf::Color(192, 16, 16),
	sf::Color(16, 255, 16),
	sf::Color(192, 16, 255)
};

int derp = 0; // remove pls

Player::Player(Dungeon& dungeon)
	:je::Entity(&dungeon, "Player", sf::Vector2f(dungeon.getWidth() / 2, dungeon.getHeight() / 2), sf::Vector2i(32, 32), sf::Vector2i(-16, -16))
	,controls(dungeon.getGame().getInput(), derp)
	,sprite(dungeon.getGame().getTexManager().get("player.png"))
	,playerID(derp++)
{
	JE_ASSERT(playerID >= 0 && playerID < maxPlayers);

	controls.setAxis("move_x_gp", je::Controller::AxisBind(sf::Joystick::Axis::X));
	controls.setAxis("move_y_gp", je::Controller::AxisBind(sf::Joystick::Axis::Y));
	controls.setAxis("move_x_kb", je::Controller::AxisBind(je::Controller::Bind(leftKeys[playerID]), je::Controller::Bind(rightKeys[playerID])));
	controls.setAxis("move_y_kb", je::Controller::AxisBind(je::Controller::Bind(upKeys[playerID]), je::Controller::Bind(downKeys[playerID])));
	const je::Axes gpAxes(controls, "move_x_gp", "move_y_gp");
	const je::Axes kbAxes(controls, "move_x_kb", "move_y_kb");
	movement = je::AxesSet({ kbAxes, gpAxes });

	controls.setAxis("aim_x_gp", je::Controller::AxisBind(sf::Joystick::Axis::U));
	controls.setAxis("aim_y_gp", je::Controller::AxisBind(sf::Joystick::Axis::R));
	aiming = je::AxesSet({ je::Axes(controls, "aim_x_gp", "aim_y_gp") });

	controls.setKeybinds("fire", {
		je::Controller::Bind(fireKeys[playerID]),
		je::Binds::X360::X,
		je::Binds::X360::RT
	});

	sprite.setColor(playerColours[playerID]);
	sprite.setOrigin(16, 16);
}

void Player::onUpdate()
{
	if (controls.isActionReleased("fire"))
	{
		level->addEntity(std::make_unique<Arrow>(level, getPos() + aiming.getPos() * 48.f, aiming.getPos() * 24.f));
	}

	if (je::length(movement.getPos()) > 0.15f)
	{
		transform().move(movement.getPos() * 3.f);

		sprite.setRotation(-je::direction(movement.getPos()));
	}
	
	if (je::length(aiming.getPos()) > 0.15f)
	{
		sprite.setRotation(-je::direction(aiming.getPos()));
	}

	sprite.setPosition(getPos());
}

void Player::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	target.draw(sprite, states);
}

} // dq
