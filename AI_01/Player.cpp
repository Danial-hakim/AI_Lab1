#include "Player.h"

void Player::init()
{
	if (!texture.loadFromFile("./sprites/playerShip2_blue.png"))
	{
		std::cout << "Error with player sprite" << std::endl;
	}

	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	sprite.setRotation(90);

	currentPosition = sf::Vector2f(500, 500);

	sprite.setPosition(currentPosition);
}

void Player::update()
{
	currentPosition.x = currentPosition.x + cos(rotation * 3.1428 / 180) * speed ;
	currentPosition.y = currentPosition.y + sin(rotation * 3.1428 / 180) * speed ;

	previousPosition = currentPosition;

	sprite.setPosition(currentPosition);
	sprite.setRotation(rotation);

	checkBoundary();
}

void Player::render(sf::RenderWindow& win)
{
	win.draw(sprite);
}

void Player::updateDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		increaseRotation();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		decreaseRotation();
	}
}

void Player::updateVelocity()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		increaseSpeed();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		decreaseSpeed();
	}
}

void Player::processGamesEvent()
{
	updateVelocity();
	updateDirection();
}

void Player::increaseSpeed()
{
	previousSpeed = speed;
	if (speed < MAX_SPEED)
	{
		speed += 1;
	}
}

void Player::decreaseSpeed()
{
	previousSpeed = speed;
	if (speed > 0)
	{
		speed -= 0.5f;
	}

	if (speed <= 0)
	{
		speed = 0  ;
	}
}

void Player::increaseRotation()
{
	previousRotation = rotation;
	rotation += 5;
	if (rotation == 360.0)
	{
		rotation = 0;
	}
}

void Player::decreaseRotation()
{
	previousRotation = rotation;
	rotation -= 5;
	if (rotation == 0.0)
	{
		rotation = 359.0;
	}
}

void Player::checkBoundary()
{
	if (currentPosition.x >= ScreenSize::s_width)
	{
		currentPosition.x = 0;
	}
	else if (currentPosition.x <= 0)
	{
		currentPosition.x = ScreenSize::s_width;
	}

	if (currentPosition.y >= ScreenSize::s_height)
	{
		currentPosition.y = 0;
	}
	else if (currentPosition.y <= 0)
	{
		currentPosition.y = ScreenSize::s_height;
	}
}

