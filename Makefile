CXX = g++
CXXFLAGS = -Wall -g
LNKRFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CXXFILES = main.cpp
APPNAME = Main
main:
	$(CXX) $(CXXFLAGS) $(CXXFILES) -o $(APPNAME) $(LNKRFLAGS)
