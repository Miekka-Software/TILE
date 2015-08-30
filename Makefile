CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -I include/
LNKRFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CXXFILES = main.cpp src/Tile.cpp src/jsoncpp.cpp src/Animate.cpp
OBJFILES = main.o src/Tile.o src/jsoncpp.o src/Animate.o
APPNAME = Main

main: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(APPNAME) $(LNKRFLAGS)
clean:
	rm -f $(APPNAME) $(OBJFILES)
