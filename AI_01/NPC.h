#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class NPC
{
public:
	void init();
	void update();
	void render(sf::RenderWindow& win);

private:

	int speed = 5;

	sf::Sprite sprite;
	sf::Texture texture;

};