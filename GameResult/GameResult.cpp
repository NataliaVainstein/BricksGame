#include "GameResult.h"

constexpr float TEXT_SIZE = 75.f;

GameResult::GameResult(Ball& _ball, Bricks& _bricks, bool& _isEndOfTheGame, sf::Vector2f& _frameDimensions)
:m_font()
,m_resultText("", m_font)
,m_ball(_ball)
,m_bricks(_bricks)
,m_isEndOfTheGame(_isEndOfTheGame)
,m_frameDimensions(_frameDimensions)
{
    m_font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    m_resultText.setCharacterSize(TEXT_SIZE);
	m_resultText.setFillColor(sf::Color::Black);
}

GameResult::~GameResult()
{
}

void GameResult::draw(Frame& _frame)
{
    if (m_bricks.isGameEnding(m_resultText) || m_ball.isGameEnding(m_resultText))
    {
        drawResult(_frame);
        m_isEndOfTheGame = true;
    }
}


void GameResult::drawResult(Frame& _frame)
{
    _frame.draw(&(this->m_resultText));
    sf::FloatRect resultTextRect = m_resultText.getLocalBounds();
    m_resultText.setOrigin(resultTextRect.left + resultTextRect.width/2.0f, resultTextRect.top + resultTextRect.height/2.0f);
    m_resultText.setPosition(sf::Vector2f(m_frameDimensions.y /2.0f, m_frameDimensions.x/2.0f));
}