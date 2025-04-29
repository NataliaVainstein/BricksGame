#ifndef __MOVABLE_BRICK__
#define __MOVABLE_BRICK__

#include "Brick.h"

class MovableBrick: public Brick
{
public:
	MovableBrick(float _height, float _width, float _xpossition, float _ypossition);
	virtual COLLISION_TYPE collide(Collision& _collideWith, int& _addPoints);
	virtual void draw(Frame& _frame);

	
private:
	bool m_hidden;
	int m_points;
};


#endif //__MOVABLE_BRICK__
