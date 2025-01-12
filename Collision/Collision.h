#ifndef __COLLISION__
#define __COLLISION__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Collision
{
public:
	enum COLLISION_TYPE
	{
		X_DIRECTION,
		Y_DIRECTION,
		NO_COLLISION
	};
	
	virtual ~Collision();
	virtual COLLISION_TYPE collide(Collision& _collideWith, int& _addPoints) = 0;
	virtual const sf::Vector2f& getShapePosition() const = 0;
	virtual const sf::Vector2f& getShapeSize() const = 0;
};


#endif //__COLLISION__
