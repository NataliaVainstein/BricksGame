#ifndef __GAME_ENDING__
#define __GAME_ENDING__

#include <SFML/Graphics.hpp>

class GameEnding
{
public:
    virtual bool isGameEnding(sf::Text& gameResultText) = 0;
    ~GameEnding();
};

#endif //__GAME_ENDING__