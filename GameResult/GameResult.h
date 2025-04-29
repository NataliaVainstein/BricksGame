#ifndef __GAME_RESULTS__
#define __GAME_RESULTS__

#include "Drawable.h"
#include "Frame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Bricks.h"

class GameResult:public Drawable
{
public:
	GameResult(Ball& _ball, Bricks& _bricks, bool& _isEndOfTheGame, sf::Vector2f& _frameDimensions);
	~GameResult();
	
	virtual void draw(Frame& _frame);
	
private:
	GameResult(const GameResult&);
	GameResult& operator=(const GameResult&);
	void drawResult(Frame& _frame);

private:	
	sf::Font m_font;
	sf::Text m_resultText;
	Ball& m_ball;
	Bricks& m_bricks;
	bool& m_isEndOfTheGame;
	sf::Vector2f& m_frameDimensions;
};

#endif //__GAME_RESULTS__

