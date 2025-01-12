#include "StableBrick.h"

StableBrick::StableBrick(float _height, float _width, float _xpossition, float _ypossition)
:Brick(_height, _width, _xpossition, _ypossition)
{
	 setFillColor(sf::Color::Blue);
}



Collision::COLLISION_TYPE StableBrick::collide(Collision& _collideWith, int& _addPoints)
{
	return X_DIRECTION;
}
