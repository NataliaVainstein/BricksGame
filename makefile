#
TARGET=brickGame
SOURCES=BrickGame.cpp Frame/Frame.cpp Ball/Ball.cpp Brick/Brick.cpp StableBrick/StableBrick.cpp MovebleBrick/MovebleBrick.cpp Pedal/Pedal.cpp Collision/Collision.cpp Bricks/Bricks.cpp GameComponents/GameComponents.cpp LevelLoader/LevelLoader.cpp Drawable/Drawable.cpp Animatable/Animatable.cpp HandlesEvent/HandlesEvent.cpp Score/Score.cpp
#
INC_DIRS = ../include Frame Ball Brick StableBrick MovebleBrick Pedal Collision Bricks Drawer GameComponents LevelLoader Drawable Animatable HandlesEvent Score
#
CC = g++
# 
CPPFLAGS = $(addprefix -I,$(INC_DIRS))
CFLAGS = -g -pedantic -ansi -Wall -Werror -DDEBUG 
CXXFLAGS += $(CFLAGS) -std=c++03
LDFLAGS = -g
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
#
.PHONY: all clean

#
OBJECTS=$(SOURCES:.cpp=.o)

all:	$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)
# Ask GCC to make the header file dependencies
include depends

depends:
	$(CC) $(CPPFLAGS) -MM $(SOURCES) > depends
	
clean: 
	rm -f $(TARGET) $(OBJECTS) depends *.gch

test:
	./$(TARGET) -v

