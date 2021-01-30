#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "directions.h"
#include <vector>

class Entity : public sf::RectangleShape
{	
	public:
		Entity(int x, int y, int size);
		bool collision(Entity * other);
		int getSize();
		int getWindowSize();
		//int getArea();
		int getX();
		int getY();
	private:
		int size;
		int windowsize;

};
#endif
