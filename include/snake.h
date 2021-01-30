#ifndef SNAKE_H
#define SNAKE_H

#include "entity.h"
#include <SFML/Graphics.hpp>
#include "directions.h"
#include "tail.h"
#include <vector>

class Snake : public Entity
{
	public:
		Snake(int size, int windowsize, int speed);
		void draw(sf::RenderTarget& target);
		void move_snake();
		void change_direction(Direction direction);
		void change_texture();
		void add_tail();
		bool check_tail_collision();
		bool wall_collision();
		int get_score();
		~Snake();
	private:
		Direction direction;
		int speed;
		int distance_traveled;
		std::vector<Tail> tail;
		sf::Texture *texture;
		sf::Texture *tail_texture;

};

#endif
