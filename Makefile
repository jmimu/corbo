#CXXFLAGS =	-O0 -g -Wall -fmessage-length=0
CXXFLAGS =	-O9

OBJS =		corbo.o Rect.o Moving_Rect.o Perso.o Camera.o Item.o Player.o Bat.o Level.o
SFML = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS = $(SFML)

TARGET =	corbo

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

Rect.o : Rect.cpp Rect.h Camera.o
	$(CXX) $(CXXFLAGS) -c Rect.cpp

Moving_Rect.o : Rect.o Moving_Rect.cpp Moving_Rect.h
	$(CXX) $(CXXFLAGS) -c Moving_Rect.cpp

Perso.o : Moving_Rect.o Perso.cpp Perso.h
	$(CXX) $(CXXFLAGS) -c Perso.cpp

Item.o : Perso.o Item.cpp Item.h
	$(CXX) $(CXXFLAGS) -c Item.cpp

Player.o : Perso.o Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

Bat.o : Perso.o Bat.cpp Bat.h
	$(CXX) $(CXXFLAGS) -c Bat.cpp
	
Camera.o : Camera.cpp Camera.h
	$(CXX) $(CXXFLAGS) -c Camera.cpp

Level.o : Rect.o Moving_Rect.o Perso.o Camera.o Item.o Player.o Bat.o Level.cpp Level.h
	$(CXX) $(CXXFLAGS) -c Level.cpp


all:	$(TARGET)

clean:
	rm -f $(OBJS)

