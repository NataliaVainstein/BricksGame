#ifndef __SCORE__
#define __SCORE__

#include "Drawable.h"
#include "Frame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class Score:public Drawable
{
public:
	Score(sf::Vector2f _position);
	~Score();
	
	void add(int _addScore);
	int getScore();
	
	virtual void draw(Frame& _frame);
	
private:
	Score(const Score&);
	Score& operator=(const Score&);

private:	
	int m_score;
	std::string m_scoreString;
	sf::Font m_font;
	sf::Text m_scoreText;  
	
};

#endif //__SCORE__
