#ifndef __GAME_RESULTS__
#define __GAME_RESULTS__

#include "Drawable.h"
#include "Frame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class GameResult:public Drawable
{
public:
	GameResult(std::string _result);
	~GameResult();
	
	virtual void draw(Frame& _frame);
	
private:
	GameResult(const GameResult&);
	GameResult& operator=(const GameResult&);

private:	
	sf::Font m_font;
	sf::Text m_resText;  
}


#endif //__GAME_RESULTS__

