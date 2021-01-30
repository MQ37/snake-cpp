#include "snake.h"
#include "tail.h"
#include <iostream>

Snake::Snake(int size, int windowsize, int speed)
: Entity(rand() % (windowsize-size), rand() % (windowsize-size), size)
{
	this->speed = speed;
	this->direction = Left;
	this->distance_traveled = 0;
	sf::Texture *texture = new sf::Texture();
	this->texture = texture;
	this->change_texture();

	sf::Texture *tail_texture = new sf::Texture();
	this->tail_texture = tail_texture;
	if (!this->tail_texture->loadFromFile("textures/tail.png"))
	{
		std::cout << "Error loading texture" << std::endl;
	}

}
Snake::~Snake()
{
	delete this->texture;
	delete this->tail_texture;
}
void Snake::draw(sf::RenderTarget& target)
{
	target.draw(*this);
	for (Tail & t : this->tail)
	{
		target.draw(t);
	}
}
void Snake::move_snake()
{
	if (this->direction == Up)
		this->move(0, -this->speed);
	else if (this->direction == Down)
		this->move(0, this->speed);
	else if (this->direction == Right)
		this->move(this->speed, 0);
	else if (this->direction == Left)
		this->move(-this->speed, 0);

	for ( Tail & t : this->tail)
	{
		t.move_tail();
	}

	this->distance_traveled += this->speed;

}
void Snake::change_direction(Direction direction)
{
	if (! (this->distance_traveled >= this->getSize()) ) return;
	if ( direction == Up && this->direction == Down ) return;
	if ( direction == Down && this->direction == Up ) return;
	if ( direction == Left && this->direction == Right ) return;
	if ( direction == Right && this->direction == Left ) return;
	this->direction = direction;
	this->distance_traveled = 0;
	for ( Tail & t : this->tail)
	{
		t.add_turnpoint(this->getX(), this->getY(), direction);
	}
	this->change_texture();
}
void Snake::add_tail()
{
	if (this->tail.size() == 0)
	{
		if (this->direction == Up)
			this->tail.emplace_back(this->getX(), this->getY() + this->speed + this->getSize(), this->getSize(), this->speed, this->direction);
		else if (this->direction == Down)
			this->tail.emplace_back(this->getX(), this->getY() - this->speed - this->getSize(), this->getSize(), this->speed, this->direction);
		else if (this->direction == Right)
			this->tail.emplace_back(this->getX() - this->speed - this->getSize(), this->getY(), this->getSize(), this->speed, this->direction);
		else if (this->direction == Left)
			this->tail.emplace_back(this->getX() + this->speed + this->getSize(), this->getY(), this->getSize(), this->speed, this->direction);
		this->tail.back().setTexture(this->tail_texture);
	}
	else
	{
		Tail & back = this->tail.back();
		if (back.getDirection() == Up)
			this->tail.emplace_back(back.getX(), back.getY() + back.getSpeed() + back.getSize(), back.getSize(), back.getSpeed(), back.getDirection());
		else if (back.getDirection() == Down)
			this->tail.emplace_back(back.getX(), back.getY() - back.getSpeed() - back.getSize(), back.getSize(), back.getSpeed(), back.getDirection());
		else if (back.getDirection() == Right)
			this->tail.emplace_back(back.getX() - back.getSpeed() - back.getSize(), back.getY(), back.getSize(), back.getSpeed(), back.getDirection());
		else if (back.getDirection() == Left)
			this->tail.emplace_back(back.getX() + back.getSpeed() + back.getSize(), back.getY(), back.getSize(), back.getSpeed(), back.getDirection());
		this->tail.back().set_turnpoints(this->tail[this->tail.size()-2].getTurnpoints());
		this->tail.back().setTexture(this->tail_texture);
		
	}
}
int Snake::get_score() { return this->tail.size(); }
bool Snake::check_tail_collision()
{
	for ( int i = 1; i < this->tail.size(); i++ )
	{
		Tail & t = this->tail[i];
		if ( this->collision(&t) ) return true;
	}
	return false;
}
bool Snake::wall_collision()
{
	if (this->getX() < 0 || this->getY() < 0 || this->getX() + this->getSize() > 600 || this->getY() + this->getSize() > 600) return true;
	return false;

}
void Snake::change_texture()
{
	if (this->direction == Up)
	{
		if (!this->texture->loadFromFile("textures/up.png"))
		{
			std::cout << "Error loading texture" << std::endl;
		}
		this->setTexture(texture);
	}
	else if (this->direction == Down)
	{
		if (!this->texture->loadFromFile("textures/down.png"))
		{
			std::cout << "Error loading texture" << std::endl;
		}
		this->setTexture(texture);
	}
	else if (this->direction == Left)
	{
		if (!this->texture->loadFromFile("textures/left.png"))
		{
			std::cout << "Error loading texture" << std::endl;
		}
		this->setTexture(texture);
	}
	else
	{
		if (!this->texture->loadFromFile("textures/right.png"))
		{
			std::cout << "Error loading texture" << std::endl;
		}
		this->setTexture(texture);
	}
}
