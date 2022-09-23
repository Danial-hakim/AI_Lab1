#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ScreenSize.h>

class NPC
{
public:
	void init();
	void update();
	void render(sf::RenderWindow& win);

	void checkBoundary();

private:

	int speed = 5;

	sf::Sprite sprite;
	sf::Texture texture;

	int xBoundary = ScreenSize::s_width;
	int yBoundary = ScreenSize::s_height;
};