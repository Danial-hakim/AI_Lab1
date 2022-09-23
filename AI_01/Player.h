#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	void init();
	void update();
	void render(sf::RenderWindow& win);
	void checkDirection();
	void updateVelocity();

	void processGamesEvent();

private:

	float speed = 5;
	sf::Vector2f direction;

	sf::Sprite sprite;
	sf::Texture texture;

};