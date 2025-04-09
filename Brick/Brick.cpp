#include "Brick.h"

Brick::Brick(float _height,	float _width, float _xposition, float _yposition)
:sf::RectangleShape (sf::Vector2f(_width, _height))
,m_height(_height)
,m_width(_width)
,m_xposition(_xposition)
,m_yposition(_yposition)
{
	
    sf::Transformable::setPosition(_xposition, _yposition);
}

Brick:: ~Brick()
{
}


void Brick::draw(Frame& _frame)
{
	_frame.draw(this);
}



Collision::COLLISION_TYPE Brick::collide(Collision& _collideWith, int& _addPoints)
{
	return NO_COLLISION; //TODO
}

const sf::Vector2f& Brick::getShapePosition() const
{
	return getPosition();
}


const sf::Vector2f& Brick::getShapeSize() const
{
	return getSize();
}
