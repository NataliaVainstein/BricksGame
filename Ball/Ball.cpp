#include "Ball.h"

Ball::Ball(float _radius,float _xPosition,float _yPosition,float _xspeed,float _yspeed)
:sf::CircleShape(_radius)
,m_radius(_radius)
,m_xposition(_xPosition)
,m_yposition(_yPosition)
,m_xspeed(_xspeed)
,m_yspeed(_yspeed)
,m_speed(_xspeed, _yspeed)
,m_squereSize(_radius * 2, _radius * 2)
{
	sf::Vector2f v(_xPosition, _yPosition);
	move(v);
    setFillColor(sf::Color::Yellow);
}

Ball::~Ball()
{
}


void Ball::animate()
{	 
	move(m_speed);
}


sf::Vector2f Ball::speed()
{
	return m_speed;
}

void Ball::draw(Frame& _frame)
{
	_frame.draw(this);
}

const sf::Vector2f& Ball::getShapeSize() const
{
	return m_squereSize;
}

const sf::Vector2f& Ball::getShapePosition() const
{
	return getPosition();
}

Collision::COLLISION_TYPE Ball::collide(Collision&  _collideWith,  int& _addPoints)
{	
	const sf::Vector2f& collideWithPos = _collideWith.getShapePosition();
	const sf::Vector2f& collideWithSize = _collideWith.getShapeSize();
	const sf::Vector2f& thisPos = getShapePosition();
	const sf::Vector2f& thisSize = getShapeSize();
	int xMultiplier = 1, yMultiplier = 1;
	bool colission = false;
	
	if(isTopButtomCollision(collideWithPos, collideWithSize, thisPos, thisSize))
	{
		colission = true;
		yMultiplier = -1;
	}
	
	if(isRightLeftCollision(collideWithPos, collideWithSize, thisPos, thisSize))
	{
		colission = true;
		xMultiplier = -1;
	}
	
	if(colission)
	{
		if(_collideWith.collide(*this, _addPoints) != NO_COLLISION)
		{
			m_speed.y *= yMultiplier;
			m_speed.x *= xMultiplier;
			
		}

		return COLLISION;
	}
	
	return NO_COLLISION;
}



bool Ball::isRightLeftCollision(const sf::Vector2f& _collideWithPos, const sf::Vector2f& _collideWithSize, const sf::Vector2f& _thisPos, const sf::Vector2f& _thisSize)
{
	float thisRightSide = _thisPos.x + _thisSize.x;
	float collideWithLeftSide = _collideWithPos.x;
	float thisLeftSide = _thisPos.x;
	float collideWithRightSide = _collideWithPos.x + _collideWithSize.x;
	
	float thisTopSide = _thisPos.y;
	float collideWithTopSide = _collideWithPos.y;
	float thisBottomSide = _thisPos.y + _thisSize.y;
	float collideWithBottomSide = _collideWithPos.y + _collideWithSize.y;
	
	if(
		(			
			(isBetween(thisLeftSide, collideWithLeftSide, collideWithRightSide) && !isBetween(thisRightSide, collideWithLeftSide, collideWithRightSide))||
			(isBetween(thisRightSide, collideWithLeftSide, collideWithRightSide)  && !isBetween(thisLeftSide, collideWithLeftSide, collideWithRightSide))
		) &&
		(
			isBetween(thisTopSide, collideWithTopSide, collideWithBottomSide)  ||
			isBetween(thisBottomSide, collideWithTopSide, collideWithBottomSide)
		)
	)
	{	
		return true;
	}
	
	return false;
}

bool Ball::isTopButtomCollision(const sf::Vector2f& _collideWithPos, const sf::Vector2f& _collideWithSize, const sf::Vector2f& _thisPos, const sf::Vector2f& _thisSize)
{
	float thisLeftSide = _thisPos.x;
	float collideWithLeftSide = _collideWithPos.x;
	float thisRightSide = _thisPos.x + _thisSize.x; 
	float collideWithRightSide = _collideWithPos.x + _collideWithSize.x; 
	
	float thisTopSide = _thisPos.y; 
	float collideWithBottomSide = _collideWithPos.y + _collideWithSize.y; 
	float thisBottomSide = _thisPos.y + _thisSize.y;
	float collideWithTopSide = _collideWithPos.y; 
	
	if(
		(			
			isBetween(thisLeftSide, collideWithLeftSide, collideWithRightSide) ||
			isBetween(thisRightSide, collideWithLeftSide, collideWithRightSide) 
		) &&
		(
			(isBetween(thisTopSide, collideWithTopSide, collideWithBottomSide) && !isBetween(thisBottomSide, collideWithTopSide, collideWithBottomSide)) ||
			(isBetween(thisBottomSide, collideWithTopSide, collideWithBottomSide) && !isBetween(thisTopSide, collideWithTopSide, collideWithBottomSide))
		)
	)
	{	
		return true;
	}
	
	return false;
}

bool Ball::isBetween(float _underTest, float _lesserBound, float _greaterBound)
{
	return (_underTest >= _lesserBound) && (_underTest <= _greaterBound);
}

