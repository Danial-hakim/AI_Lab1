#include "NPC.h"

void NPC::init()
{
	if (!texture.loadFromFile("./sprites/ufoRed.png"))
	{
		std::cout << "Error with npc sprite" << std::endl;
	}

	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	sprite.setRotation(90);

	sprite.setPosition(500, 500);
}

void NPC::update()
{
	checkBoundary();
	sprite.move(3, 0);
}

void NPC::render(sf::RenderWindow& win)
{
	win.draw(sprite);
}

void NPC::checkBoundary()
{
	if (sprite.getPosition().x - texture.getSize().x >= xBoundary)
	{
		sprite.setPosition(0, sprite.getPosition().y);
	}
}

