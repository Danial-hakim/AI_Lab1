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

	sprite.setPosition(100, 100);
}

void Player::update()
{
	sprite.move(direction * speed);
}

void Player::render(sf::RenderWindow& win)
{
	win.draw(sprite);
}

void Player::checkDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction = sf::Vector2f(-1,0);
		sprite.setScale(1, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction = sf::Vector2f(1,0);
		sprite.setScale(1, 1);
	}
}

void Player::updateVelocity()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed += 0.5f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed -= 0.5f;
	}

	if (speed >= 10)
	{
		speed = 10;
	}
	else if (speed <= 1)
	{
		speed = 1;
	}

	std::cout << speed << std::endl;
}

void Player::processGamesEvent()
{
	updateVelocity();
	checkDirection();
}
