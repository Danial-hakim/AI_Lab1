#include "Seek.h"

SteeringOutput Seek::getSteering()
{
    steering.linear = m_playerPos - currentPosition;

    std::cout << currentPosition.x << std::endl;

    Maths::unitVector(steering.linear);
    steering.linear *= maxAcceleration;

    steering.angular = 0;
    return steering;
}
