CXX := g++
CXXFLAGS := -std=c++2a

CPPFLAGS := -I../include -I../include/SDL2 -I../include/headers 
LDLIBS := -L../lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

sourceFiles := ../src/*.cpp 
appName := game.sh

all:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(appName) $(sourceFiles) $(LDLIBS)
run:
	./game.sh