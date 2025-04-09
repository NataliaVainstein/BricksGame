#ifndef __GAME_COMPONENTS__
#define __GAME_COMPONENTS__


#include "Frame.h"
#include "Brick.h"
#include "Bricks.h"
#include "Pedal.h"
#include "Ball.h"
#include "Score.h"

class GameComponents
{
public: 	
	GameComponents(sf::Vector2f& _frameDimensions, sf::Vector2f& _framePosition);
	~GameComponents();
	
	void draw();
	void handleEvent(sf::Event _event);
	void animate();
	void collide();
	bool gameOver();
	
	void run();
private:
	GameComponents(const GameComponents&);
	GameComponents& operator=(const GameComponents&);
	
private:
	Frame m_frame;
	Ball m_ball;
	Bricks m_bricks;
	Pedal m_pedal;
	Score m_score;
	sf::Vector2f& m_frameDimensions;
};

#endif //__GAME_COMPONENTS__
