#include "NPC.h"

void NPC::init()
{
	if (!texture.loadFromFile("./sprites/playerShip1_green.png"))
	{
		std::cout << "Error with npc sprite" << std::endl;
	}

	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	//sprite.setRotation(90);

	sprite.setPosition(500, 500);

	//m_playerPos = playerPos;
}

void NPC::update(float dt, sf::Vector2f playerPos, int enemyType)
{
	m_playerPos = playerPos;

	checkBoundary();
	getSteering(enemyType);
	kinematicsUpdate(dt);

	updateMovement();

	/*std::cout << currentPosition.x << std::endl;
	std::cout << currentPosition.y << std::endl;*/
}

void NPC::render(sf::RenderWindow& win)
{
	win.draw(sprite);
}

void NPC::checkBoundary()
{
	currentPosition = sprite.getPosition();

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

	sprite.setPosition(currentPosition);
}

void NPC::kinematicsUpdate(float dt)
{
	//Update the positionand orientation
	kinematics.position = sprite.getPosition();
	kinematics.orientation = sprite.getRotation();

	kinematics.position += kinematics.velocity * (dt / 1000.0f);
	kinematics.orientation += kinematics.rotation * (dt / 1000.0f);

	//Update the velocity and rotation
	kinematics.velocity += steering.linear * (dt / 1000.0f);
	kinematics.orientation += steering.angular * (dt / 1000.0f);

	if (Maths::length(kinematics.velocity) > maxSpeed)
	{
		Maths::unitVector(kinematics.velocity);
		kinematics.velocity *= maxSpeed;
	}
}

void NPC::getSteering(int enemyType)
{
	switch (enemyType)
	{
	case 1:
		steering.linear = m_playerPos - currentPosition;

		Maths::unitVector(steering.linear);
		steering.linear *= maxAcceleration;

		steering.angular = 0;
		break;

	case 2:

		steering.linear = currentPosition - m_playerPos;

		Maths::unitVector(steering.linear);
		steering.linear *= maxAcceleration;

		steering.angular = 0;
		break;
	}
}

void NPC::updateMovement()
{
	sprite.setPosition(kinematics.position);
	sprite.setRotation(kinematics.rotation);

	std::cout << kinematics.position.x << std::endl;
}

