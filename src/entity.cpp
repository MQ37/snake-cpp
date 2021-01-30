#include <SFML/Graphics.hpp>
#include "directions.h"
#include "entity.h"
#include <iostream>

Entity::Entity(int x, int y, int size)
{
	this->size = size;
	this->windowsize = windowsize;
	
	this->setSize(sf::Vector2f(size, size));
	this->setPosition(x, y);
}
bool Entity::collision(Entity * other)
{
	if (this->getX() + this->getSize() >= other->getX() && other->getX() + other->getSize() >= this->getX())
	{
		if (this->getY() + this->getSize() >= other->getY() && other->getY() + other->getSize() >= this->getY())
		{
			return true;
		}

	}
	return false;

}
int Entity::getSize() { return this->size; }
int Entity::getWindowSize() { return this->windowsize; }
//int Entity::getArea() { return this->size * 2; }
int Entity::getX() { return this->getPosition().x; }
int Entity::getY() { return this->getPosition().y; }
