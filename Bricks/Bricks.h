#ifndef __BRICKS__
#define __BRICKS__

#include "Brick.h"
#include "Frame.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



class Bricks
{
public:
	Bricks(sf::Vector2f& _frameDimension);
	~Bricks();
	
	enum collideWithEnum
	{
		_ALL_BRICKS,
		_HORIZONTAL_FRAME_BRICKS_
	};
	
	void draw(Frame& _frame);
	void collide(Collision& _collideWith, Bricks::collideWithEnum _collideType, int& _points);
	Brick* getBrick(size_t i);
	
private: 
	Bricks(const Bricks&);
	Bricks& operator=(const Bricks&); 
	void addBrick(char c, int _posX, int _posY);
	
private:
	std::vector<Brick*> m_shapes;
};

#endif //__BRICKS__
