#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	void init();
	void update();
	void render(sf::RenderWindow& win);
	void updateDirection();
	void updateVelocity();

	void processGamesEvent();

private:

	float speed = 1;
	sf::Vector2f direction = { 1, 0 };

	sf::Sprite sprite;
	sf::Texture texture;

	float rotation;
};