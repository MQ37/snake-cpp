#include <SFML/Graphics.hpp>
#include "directions.h"
#include "snake.h"

void handle_keypress(sf::Event event, Snake & snake)
{
	if (event.key.code == sf::Keyboard::Up)
	{
		snake.change_direction(Up);
	}
	else if(event.key.code == sf::Keyboard::Down)
	{
		snake.change_direction(Down);
	}
	else if(event.key.code == sf::Keyboard::Left)
	{
		snake.change_direction(Left);
	}
	else if(event.key.code == sf::Keyboard::Right)
	{
		snake.change_direction(Right);
	}

}
