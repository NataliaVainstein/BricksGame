#ifndef __STABLE_BRICK__
#define __STABLE_BRICK__

#include "Brick.h"

class StableBrick: public Brick
{
public:
	StableBrick(float _height, float _width, float _xpossition, float _ypossition);
	virtual COLLISION_TYPE collide(Collision& _collideWith, int& _addPoints);
};


#endif //__STABLE_BRICK__
