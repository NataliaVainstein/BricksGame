#ifndef __PEDAL__
#define __PEDAL__

#include "Frame.h"
#include "Collision.h"
#include "Drawable.h"
#include "Animatable.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Pedal:public Animatable, public Drawable, public Collision, public sf::RectangleShape 
{
public:
	Pedal(float _height, float _width, float _xpossition, float _ypossition);
	~Pedal();
	void animate();
	void draw(Frame& _frame);
	void updateXOffset(float _xOffset);
	
	COLLISION_TYPE collide(Collision& _collideWith, int& _addPoints);
	virtual const sf::Vector2f& getShapePosition() const;
	virtual const sf::Vector2f& getShapeSize() const;
	void handleEvent(sf::Event _event);
	
private:
	bool isEqualSmaller(float _first, float _second);
	bool isEqualBigger(float _first, float _second);
	bool isLeftCollision(float _thisPosLeftSide, float _collideWithPosLeftSide, float _collideWithSize , float _thisSize);
	bool isRightCollision(float _thisPosLeftSide, float _collideWithPosLeftSide, float _collideWithSize);
	
private:
	float m_height;
	float m_width;
	float m_xpossition;
	float m_ypossition;
	float m_xOffset;
};


#endif //__PEDAL__
