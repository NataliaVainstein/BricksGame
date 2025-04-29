#ifndef __BRICK__
#define __BRICK__

#include "Frame.h"
#include "Collision.h"
#include "Drawable.h"
#include "Animatable.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Brick:public Drawable, public Collision, public sf::RectangleShape
{
public:
	Brick(float _height, float _width, float _xposition, float _yposition);
	~Brick();
	virtual void draw(Frame& _frame);

	virtual COLLISION_TYPE collide(Collision& _collideWith, int& _addPoints) = 0;
	virtual const sf::Vector2f& getShapePosition() const;
	virtual const sf::Vector2f& getShapeSize() const;
	
private:	
	float m_height;
	float m_width;
	float m_xposition;
	float m_yposition;
};

#endif //__BRICK__
