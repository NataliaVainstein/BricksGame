#include "Brick.h"

Brick::Brick(float _height,	float _width, float _xpossition, float _ypossition)
:sf::RectangleShape (sf::Vector2f(_width, _height))
,m_height(_height)
,m_width(_width)
,m_xpossition(_xpossition)
,m_ypossition(_ypossition)
{
	
    sf::Transformable::setPosition(_xpossition, _ypossition);
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
