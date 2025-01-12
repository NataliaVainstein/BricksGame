#ifndef __BALL__
#define __BALL__

#include "Frame.h"
#include "Collision.h"
#include "Drawable.h"
#include "Animatable.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ball:public Animatable, public Drawable, public Collision, public sf::CircleShape
{
public:
	Ball(float _radius,float _xPossition,float _yPossition,float _xspeed,float _yspeed);
	~Ball();

	void animate();
	void draw(Frame& _frame);
	
	sf::Vector2f speed();
	const sf::Vector2f& getShapeSize() const;
	const sf::Vector2f& getShapePosition() const;
	
	COLLISION_TYPE collide(Collision& _collideWith,  int& _addPoints);
	bool isRightLeftCollision(const sf::Vector2f& _collideWithPos, const sf::Vector2f& _collideWithSize, const sf::Vector2f& _thisPos, const sf::Vector2f& _thisSize);
	bool isTopButtomCollision(const sf::Vector2f& _collideWithPos, const sf::Vector2f& _collideWithSize, const sf::Vector2f& _thisPos, const sf::Vector2f& _thisSize);

private: 
	bool isBetween(float _underTest, float _lesserBound, float _greaterBound);
	
private:	
	float m_radius;
	float m_xpossition;
	float m_ypossition;
	float m_xspeed;
	float m_yspeed;
	sf::Vector2f m_speed;
	sf::Vector2f m_squereSize;
};


#endif //__BALL__
