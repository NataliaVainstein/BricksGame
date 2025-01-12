#ifndef __MOVEBLE_BRICK__
#define __MOVEBLE_BRICK__

#include "Brick.h"

class MovebleBrick: public Brick
{
public:
	MovebleBrick(float _height, float _width, float _xpossition, float _ypossition);
	virtual COLLISION_TYPE collide(Collision& _collideWith, int& _addPoints);
	virtual void draw(Frame& _frame);

	
private:
	bool m_hidden;
	int m_points;
};


#endif //__MOVEBLE_BRICK__
