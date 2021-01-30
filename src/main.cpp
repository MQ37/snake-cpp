#include <chrono>
#include <thread>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "directions.h"
#include "snake.h"
#include "food.h"
#include "keyboard_handler.h"
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Hadoslav");
    Snake snake(30, 600, 5);
    Food * food = new Food(30, 600);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
	    std::cout << "CANNOT LOAD FONT" << std::endl;
    }
    sf::Text score;
    score.setFont(font);
    score.setFillColor(sf::Color::Red);
    score.setCharacterSize(30);
    score.setString("0");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
	    else if (event.type == sf::Event::KeyPressed)
	    {
		    handle_keypress(event, snake);
	    }
        }

	// Game loop
	snake.move_snake();
	if (snake.check_tail_collision())
	{
		std::cout << "Had se kousk, prohrál jsi!" << std::endl;
		delete food;
		return 0;
	}
	if (snake.wall_collision())
	{
		std::cout << "Had narazil do zdi, prohrál jsi!" << std::endl;
		delete food;
		return 0;
	}
	if (snake.collision(food)){
		delete food;
		food = new Food(30, 600);
		snake.add_tail();
		score.setString( std::to_string(snake.get_score()) );
	}

	// Drawing
        window.clear();
	window.draw(score);
	window.draw(*food);
	snake.draw(window);
        window.display();

	// Sleep
	std::this_thread::sleep_for( std::chrono::milliseconds(50) );
    }

    delete food;
    return 0;
}
