CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LNKRFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CXXFILES = main.cpp Tile.cpp
APPNAME = Main
main:
	$(CXX) $(CXXFLAGS) $(CXXFILES) -o $(APPNAME) $(LNKRFLAGS)
