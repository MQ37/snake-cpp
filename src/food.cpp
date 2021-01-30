#include "food.h"
#include <iostream>

Food::Food(int size, int windowsize)
: Entity(rand() % (windowsize-size), rand() % (windowsize-size), size)
{
	sf::Texture *texture = new sf::Texture();
	this->texture = texture;
	if (!this->texture->loadFromFile("textures/food.png"))
	{
		std::cout << "Error loading texture" << std::endl;
	}
	this->setTexture(this->texture);
}
Food::~Food()
{
	delete this->texture;
}
