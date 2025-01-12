#include "Frame.h"
#include "Ball.h"
#include "Brick.h"
#include "Bricks.h"
#include "Pedal.h"
#include "GameComponents.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#define NUM_BRICKS 11

int main()
{
	Frame f(800, 600, 200, 100);
	GameComponents gameComp(f);
	
	Ball ball(20, 10, 50, 2, 3);
	Brick brButtom(10.f ,900.f, -10.f, 580.f); //temporal for testing
	Brick brTop(0.5,900.f, 0.f, 0.f);
	Brick brLeft(700.f, 100, -100.f, 0.f);
	Brick brRight(700.f,100, 800.f, 0.f);
	
	Brick br1(40.f,100.f, 10.f, 11.f);
	Brick br2(40.f,100.f, 120.f, 10.f);
	Brick br3(40.f,100.f, 230.f, 10.f);
	Brick br4(40.f,100.f, 340.f, 10.f);
	Brick br5(40.f,100.f, 460.f, 10.f);
	Brick br6(40.f,100.f, 570.f, 10.f);
	Brick br7(40.f,100.f, 680.f, 10.f);
	Brick barr[NUM_BRICKS] = {brButtom, brTop, brLeft, brRight, br1, br2, br3, br4, br5, br6, br7};
	Pedal p(40.f, 100.f, 20.f, 545.f);
	
	Bricks bs(f);
	bs.draw(f);
	while(f.isOpen())
	{	
		sf::Event e = f.pollEvents();
		f.handleEvent(e);
		p.handleEvent(e);
		ball.animate();
		f.clear();
		ball.draw(f);
		bs.draw(f);
	/*	for(size_t i = 0; i < NUM_BRICKS; ++i)
		{
			barr[i].draw(f);
			ball.collide(barr[i]);
		}*/

	//	p.updateXOffset(pedalMove);
		p.animate();
		p.draw(f);
		f.display();
		/*ball.collide(brButtom);
		ball.collide(brTop);
		ball.collide(brLeft);
		ball.collide(brRight);
		ball.collide(br1);
		ball.collide(br2);
		ball.collide(br3);
		ball.collide(br4);
		ball.collide(br5);
		ball.collide(br6);
		ball.collide(br7);*/
		ball.collide(p);
		p.collide(brLeft);
		p.collide(brRight);
	}
	
	
	return 0;
	
}
