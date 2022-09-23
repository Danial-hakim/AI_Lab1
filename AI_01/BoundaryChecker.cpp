#include "BoundaryChecker.h"

void BoundaryChecker::checkBoundary(sf::Sprite& sprite)
{
	sf::Vector2f currentPos = sprite.getPosition();

	if (currentPos.x >= ScreenSize::s_width)
	{
		currentPos.x = 0;
	}
	else if (currentPos.x <= 0)
	{
		currentPos.x = ScreenSize::s_width;
	}

	if (currentPos.y >= ScreenSize::s_height)
	{
		currentPos.y = 0;
	}
	else if (currentPos.y <= 0)
	{
		currentPos.y = ScreenSize::s_height;
	}
	
	std::cout << sprite.getPosition().x << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << currentPos.x << std::endl;
}
