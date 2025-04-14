#include "Bricks.h"
#include "StableBrick.h"
#include "MovebleBrick.h"
#include "LevelLoader.h"
#include <string>
#include <vector>
#include "Ball.h"


class Drawer
{
public: 
	Drawer(Frame& _frame)
	:m_frame(_frame)
	{
	}
	void operator()(Brick* _br)
	{
		_br->draw(m_frame);
	}
private:
		Frame& m_frame;
};

class Collider
{
public:
	Collider(Collision& _collideWith, int& _points)
	:m_collideWith(_collideWith)
	,m_points(_points)
	{
	}
	void operator()(Brick* _br)
	{
		m_collideWith.collide(*_br, m_points);
	}
private:
	Collision& m_collideWith;
	int& m_points;
};
	

constexpr float OFFSET  = 15.f;
constexpr float OFFSET_Y = 20.f;
constexpr float BRICKS_INTERVAL  = 10.f;
constexpr float BRICK_HEIGHT = 40.f;
constexpr float BRICK_WIDTH = 100.f;
constexpr float LEFT_STABLE_BRICK_Y_POSITION = 0.f;
constexpr float RIGHT_STABLE_BRICK_Y_POSITION = 0.f;
constexpr float TOP_STABLE_BRICK_X_POSITION = 0.f;

Bricks::Bricks(sf::Vector2f& _frameDimension)
{	

	Brick*  brLeft = new StableBrick(_frameDimension.x, BRICK_WIDTH, -BRICK_WIDTH, LEFT_STABLE_BRICK_Y_POSITION);
	Brick*  brRight = new StableBrick(_frameDimension.x,BRICK_WIDTH, _frameDimension.y, RIGHT_STABLE_BRICK_Y_POSITION);
	Brick* brTop = new StableBrick(BRICK_HEIGHT, _frameDimension.y, TOP_STABLE_BRICK_X_POSITION, -BRICK_HEIGHT);
	
	m_shapes.push_back(brLeft);
	m_shapes.push_back(brRight);
	m_shapes.push_back(brTop);
	
	std::string levelStr("level1.txt");
	LevelLoader level(levelStr);
	
	int numLine = 0; 
	float posX = OFFSET;
	bool readLineRes = true;
	float posY = OFFSET_Y + BRICKS_INTERVAL + numLine * (BRICKS_INTERVAL + BRICK_HEIGHT);
	 std::string brickLine;
	
	do{
		readLineRes = level.getLine(brickLine);
		if(readLineRes)
		{
			std::string::iterator endItr = brickLine.end();
			for(std::string::iterator it = brickLine.begin(); it != endItr; ++it)
			{
				if(*it != ' ')
				{
					addBrick(*it, posX, posY);
				}
				
				posX += BRICK_WIDTH + BRICKS_INTERVAL;
			}
		}
		
		posX = OFFSET;
		++numLine;
		posY = OFFSET_Y + BRICKS_INTERVAL + numLine * (BRICKS_INTERVAL + BRICK_HEIGHT);
	}while(readLineRes);
		
}

Bricks::~Bricks()
{
}

void Bricks:: addBrick(char c, int _posX, int _posY)
{
	Brick* b;
	
	if(c == 'N')
	{
		b = new MovebleBrick(BRICK_HEIGHT, BRICK_WIDTH, _posX, _posY);
	}
	if(c == 'S')
	{
		b = new StableBrick(BRICK_HEIGHT, BRICK_WIDTH, _posX, _posY);
	}
	
	m_shapes.push_back(b);
}

void Bricks::draw(Frame& _frame)
{
	std::for_each(m_shapes.begin(), m_shapes.end(), Drawer(_frame));
}

void Bricks::collide(Collision& _collideWith, Bricks::collideWithEnum _collideType, int& _points)
{
	if(_collideType == _ALL_BRICKS)
	{
		std::for_each(m_shapes.begin(), m_shapes.end(), Collider(_collideWith, _points));
	}
	else
	{
		_collideWith.collide(*m_shapes[0], _points);
		_collideWith.collide(*m_shapes[1], _points);
	}
}

Brick* Bricks::getBrick(size_t i)
{
	return m_shapes[i];
}

