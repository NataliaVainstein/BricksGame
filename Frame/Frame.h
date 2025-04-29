#ifndef __FRAME__
#define __FRAME__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Frame 
{
public:

	Frame(sf::Vector2f& _frameDimensions, sf::Vector2f& _framePossition);
	~Frame();
		
	
	void display();
	bool isOpen();
	
	void draw(sf::Drawable* _shape);
	sf::Event pollEvents();
	void clear();
	void handleEvent(sf::Event _event);
	
	const sf::Vector2f& frameDimensions() const;
	
private:
	Frame(const Frame& _frame);
	Frame& operator=(const Frame&); 
	
private:
	const sf::Vector2f m_frameDimensions;
	sf::RenderWindow m_frame;
};

#endif //__FRAME__
