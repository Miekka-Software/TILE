CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -I include/
LNKRFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CXXFILES = main.cpp src/Tile.cpp src/jsoncpp.cpp
APPNAME = Main
main:
	$(CXX) $(CXXFLAGS) $(CXXFILES) -o $(APPNAME) $(LNKRFLAGS)
