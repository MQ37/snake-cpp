#ifndef TAIL_H
#define TAIL_H

#include "entity.h"
#include "directions.h"
#include <vector>

class Tail : public Entity
{
	public:
		Tail(int x, int y, int size, int speed, Direction direction);
		void move_tail();
		void change_direction(Direction direction);
		void add_turnpoint(int x, int y, Direction direction);
		void remove_turnpoint();
		void set_turnpoints(std::vector<std::tuple<int, int, Direction>> turnpoints);
		Direction getDirection();
		int getSpeed();
		std::vector<std::tuple<int, int, Direction>> getTurnpoints();
	private:
		Direction direction;
		int speed;
		std::vector<std::tuple<int, int, Direction>> turnpoints;

};

#endif
