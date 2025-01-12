#ifndef __DRAWABLE__
#define __DRAWABLE__

#include "Frame.h"

class Drawable
{
public:
	virtual void draw(Frame& _frame) = 0;
	virtual ~Drawable();
};


#endif //__DRAWABLE__
