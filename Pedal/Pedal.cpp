#include "Pedal.h"

constexpr float PEDAL_Y_OFFSET = 0.f;
constexpr float PEDAL_DEFAULT_X_OFFSET = 0.f;
constexpr float PEDAL_RIGHT_COLLISION_X_OFFSET = -1.f;
constexpr float PEDAL_LEFT_COLLISION_X_OFFSET = 1.f;
constexpr float RIGHT_KEY_PRESSED_X_OFFSET = 5.f;
constexpr float LEFT_KEY_PRESSED_X_OFFSET = -5.f;

Pedal::Pedal(float _height, float _width, float _xpossition, float _ypossition)
:sf::RectangleShape (sf::Vector2f(_width, _height))
,m_height(_height)
,m_width(_width)
,m_xpossition(_xpossition)
,m_ypossition(_ypossition)
,m_xOffset(0)
{
	setPosition(_xpossition, _ypossition);
    setFillColor(sf::Color::Black);
}

Pedal::~Pedal()
{
}

void Pedal::animate()
{
	move(m_xOffset, PEDAL_Y_OFFSET);
	updateXOffset(PEDAL_DEFAULT_X_OFFSET);
}

void Pedal::draw(Frame& _frame)
{
	_frame.draw(this);
}

void Pedal::updateXOffset(float _xOffset)
{
	m_xOffset = _xOffset;
}

const sf::Vector2f& Pedal::getShapePosition() const
{
	return getPosition();
}


const sf::Vector2f& Pedal::getShapeSize() const
{
	return getSize();
}

Collision::COLLISION_TYPE Pedal::collide(Collision& _collideWith, int& _addPoints)
{
	const sf::Vector2f& collideWithPos = _collideWith.getShapePosition();
	const sf::Vector2f& collideWithSize = _collideWith.getShapeSize();
	const sf::Vector2f& thisPos = getShapePosition();
	const sf::Vector2f& thisSize = getShapeSize();
	
	if((isRightCollision(thisPos.x, thisSize.x, collideWithPos.x)))
	{
		updateXOffset(PEDAL_RIGHT_COLLISION_X_OFFSET);
	
		return X_DIRECTION;
	}
	
	if(isLeftCollision(thisPos.x,collideWithPos.x, collideWithSize.x, thisSize.x))
	{
		updateXOffset(PEDAL_LEFT_COLLISION_X_OFFSET);
		
		return X_DIRECTION;
	}
	
	return NO_COLLISION;
}

bool Pedal::isRightCollision(float _thisPosLeftSide, float _thisSize, float _collideWithPosLeftSide)
{
	float thisRightSide = _thisPosLeftSide + _thisSize;
	
	if(isEqualBigger(thisRightSide, _collideWithPosLeftSide) && isEqualSmaller(_thisPosLeftSide, _collideWithPosLeftSide))
	{
		return true;
	}
	return false;
}

bool Pedal::isLeftCollision(float _thisPosLeftSide, float _collideWithPosLeftSide, float _collideWithSize, float _thisSize)
{
	float collideWithRightSize = _collideWithPosLeftSide + _collideWithSize;
	float thisPosRightSize = _thisPosLeftSide + _thisSize;
	
	if(isEqualSmaller(_thisPosLeftSide, collideWithRightSize) && isEqualBigger(thisPosRightSize, _collideWithPosLeftSide))
	{
		return true;
	}
	
	return false;
}

bool Pedal::isEqualBigger(float _first, float _second)
{
	return _first >= _second;
}

bool Pedal::isEqualSmaller(float _first, float _second)
{
	return _first <= _second;
}

void Pedal::handleEvent(sf::Event _event)
{
	switch(_event.type)
	{
		case sf::Event::KeyPressed:
			switch(_event.key.code)
			{
				case sf::Keyboard::Right:
					updateXOffset(RIGHT_KEY_PRESSED_X_OFFSET);
					break;
				case sf::Keyboard::Left:
					updateXOffset(LEFT_KEY_PRESSED_X_OFFSET);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}
