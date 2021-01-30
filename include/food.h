#ifndef FOOD_H
#define FOOD_H

#include "entity.h"

class Food : public Entity
{
	public:
		Food(int size, int windowsize);
		~Food();
	private:
		sf::Texture *texture;
};

#endif
