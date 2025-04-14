#include "MovebleBrick.h"

constexpr int MOVEBLE_BRICK_POINTS = 10;

MovebleBrick::MovebleBrick(float _height, float _width, float _xpossition, float _ypossition)
:Brick(_height, _width, _xpossition, _ypossition)
,m_hidden(false)
,m_points(MOVEBLE_BRICK_POINTS)
{
	 setFillColor(sf::Color::White);
}


Collision::COLLISION_TYPE MovebleBrick::collide(Collision& _collideWith, int& _addPoints)
{
	if(m_hidden)
	{
		return NO_COLLISION;
	}
	
	m_hidden = true;
	_addPoints = m_points;
	
	return COLLISION;
}

void MovebleBrick::draw(Frame& _frame)
{
	if(!m_hidden)
	{
		_frame.draw(this);
	}
}

