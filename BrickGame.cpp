#include "Frame.h"
#include "Ball.h"
#include "Brick.h"
#include "Bricks.h"
#include "Pedal.h"
#include "GameComponents.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	sf::Vector2f frameDimensions(600, 800);
	sf::Vector2f framePossition(200, 100);
	GameComponents game(frameDimensions, framePossition);
	game.run();


	return 0;
}
