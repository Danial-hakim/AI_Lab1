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
	
}

void NPC::render(sf::RenderWindow& win)
{
	win.draw(sprite);
}
