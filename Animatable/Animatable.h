#ifndef __ANIMATABLE__
#define __ANIMATABLE__

class Animatable
{
public:
	virtual ~Animatable();
	virtual void animate() = 0;
};

#endif //__ANIMATABLE__
