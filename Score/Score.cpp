#include "Score.h"
#include <sstream>

constexpr float SCORE_TEXT_SIZE = 20.f;

Score::Score(sf::Vector2f _position)
:m_score(0)
,m_scoreString("Score: ")
,m_font()
,m_scoreText(m_scoreString, m_font)
{
	m_font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");
	m_scoreText.setCharacterSize(SCORE_TEXT_SIZE);
	m_scoreText.setFillColor(sf::Color::Black);
	m_scoreText.setPosition(_position);
}

Score::~Score()
{
}

void Score::add(int _addScore)
{
	m_score += _addScore;
}

int Score::getScore()
{
	return m_score;
}

void Score::draw(Frame& _frame)
{
	std::stringstream ss;
	ss << "Score: " << m_score ;
	m_scoreString = ss.str();
	m_scoreText.setString(m_scoreString);
	_frame.draw(&(this->m_scoreText));
}
