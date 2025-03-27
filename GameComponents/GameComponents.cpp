#include "GameComponents.h"


GameComponents::GameComponents(sf::Vector2f& _frameDimensions, sf::Vector2f& _framePossition)
:m_frame(_frameDimensions, _framePossition)
,m_ball(10, 50, 200, 2, 3)
,m_bricks(_frameDimensions)
,m_pedal(40.f, 150.f, 300.f, 500.f)
,m_score(sf::Vector2f(0, _frameDimensions.y - 270))
,m_frameDimensions(_frameDimensions)
{
}

GameComponents::~GameComponents()
{
}

void GameComponents:: draw()
{
	m_frame.clear();
	m_ball.draw(m_frame);
	m_bricks.draw(m_frame);
	m_pedal.draw(m_frame);
	m_score.draw(m_frame);
	m_frame.display();
}

void GameComponents::handleEvent(sf::Event _event)
{
	m_frame.handleEvent(_event);
	m_pedal.handleEvent(_event);
}

void  GameComponents::animate()
{

	m_ball.animate();
	m_pedal.animate();
}

void GameComponents::collide()
{
	int points = 0;
	m_bricks.collide(m_ball, Bricks::_ALL_BRICKS, points);
	m_bricks.collide(m_pedal, Bricks::_HORIZONTAL_FRAME_BRICKS_, points);
	m_ball.collide(m_pedal, points);
	m_score.add(points);
}

bool GameComponents::gameOver()
{
	const sf::Vector2f& ballPosition = m_ball.getShapePosition();
	if(ballPosition.y > m_frameDimensions.y)
	{
		return true; 
	}
	return false;
}

void GameComponents:: run()
{
	bool gameOver = false;
	while(m_frame.isOpen() && !gameOver)
	{	
		draw();
		sf::Event e = m_frame.pollEvents();
		handleEvent(e);
		collide();
		animate();	
	}
	
}
