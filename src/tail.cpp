#include "tail.h"

Tail::Tail(int x, int y, int size, int speed, Direction direction)
: Entity(x, y, size)
{
	this->direction = direction;
	this->speed = speed;
}
void Tail::move_tail()
{
	if (this->direction == Up)
		this->move(0, -this->speed);
	else if (this->direction == Down)
		this->move(0, this->speed);
	else if (this->direction == Right)
		this->move(this->speed, 0);
	else if (this->direction == Left)
		this->move(-this->speed, 0);

	if (this->turnpoints.size() > 0)
	{
		std::tuple<int, int, Direction> tp = this->turnpoints.back();
		if (this->getX() == std::get<0>(tp) && this->getY() == std::get<1>(tp))
		{
			this->direction = std::get<2>(tp);
			this->turnpoints.pop_back();
		}
		
	}
		
}
void Tail::add_turnpoint(int x, int y, Direction direction)
{
	this->turnpoints.emplace(this->turnpoints.begin(), x, y, direction);

}
void Tail::set_turnpoints( std::vector<std::tuple<int, int, Direction>> turnpoints )
{
	this->turnpoints = turnpoints;

}
std::vector<std::tuple<int, int, Direction>> Tail::getTurnpoints() { return this->turnpoints; }
Direction Tail::getDirection() { return this->direction; }
int Tail::getSpeed() { return this->speed; }
