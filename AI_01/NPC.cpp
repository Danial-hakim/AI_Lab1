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

	if (enemyType != 2)
	{
checkBoundary();
	}
	else
	{
	resetToMiddle();
	}

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
	case 1: // seek
		steering.linear = m_playerPos - currentPosition;

		Maths::unitVector(steering.linear);
		steering.linear *= maxAcceleration;

		updateOrientation(rotation, steering.linear);

		steering.angular = 0;
		break;

	case 2: // flee

		steering.linear = currentPosition - m_playerPos;

		Maths::unitVector(steering.linear);
		steering.linear *= (maxAcceleration / 2);

		updateOrientation(rotation, steering.linear);

		steering.angular = 0;
		break;

	case 3: // Arrive

		float rad = 5.0f;

		steering.linear = m_playerPos - currentPosition;

		if (Maths::length(steering.linear) > rad)
		{
			steering.linear /= 0.25f;
		};

		//if(steering.linear)



	}
}

void NPC::updateMovement()
{
	sprite.setPosition(kinematics.position);
	sprite.setRotation(rotation);
}

void NPC::updateOrientation(float currentOrientation, sf::Vector2f velocity)
{
	if (Maths::length(velocity) > 0)
	{
		rotation = Maths::radiansToDegree(std::atan2f(velocity.y, velocity.x));
	}
	else
	{
		rotation = currentOrientation;
	}
}

void NPC::resetToMiddle()
{
	currentPosition = sprite.getPosition();

	if (currentPosition.x >= ScreenSize::s_width || currentPosition.x <= 0)
	{
		currentPosition.x = ScreenSize::s_width / 2.0f;
	}

	if (currentPosition.y >= ScreenSize::s_height || currentPosition.y <= 0)
	{
		currentPosition.y = ScreenSize::s_height / 2.0f;
	}

	sprite.setPosition(currentPosition);
}

