#ifndef __HANDLES_EVENT__
#define __HANDLES_EVENT__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class HandlesEvent
{
public:
	virtual ~HandlesEvent();
	virtual void handleEvent(sf::Event _event) = 0;
};

#endif //__HANDLES_EVENT__
