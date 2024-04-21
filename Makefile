CXX = g++
CXXFLAGS = -Wall -g
OBJS = BombBot.o FastBot.o main.o Map.o Robo.o SortBot.o

all: myprogram

myprogram: $(OBJS)
	$(CXX) $(CXXFLAGS) -o myprogram $(OBJS)

BombBot.o: BombBot.cpp BombBot.h
	$(CXX) $(CXXFLAGS) -c BombBot.cpp

Command.o: Command.cpp Command.h
	$(CXX) $(CXXFLAGS) -c Command.cpp

FastBot.o: FastBot.cpp FastBot.h
	$(CXX) $(CXXFLAGS) -c FastBot.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Map.o: Map.cpp Map.h
	$(CXX) $(CXXFLAGS) -c Map.cpp

Robo.o: Robo.cpp Robo.h
	$(CXX) $(CXXFLAGS) -c Robo.cpp

SortBot.o: SortBot.cpp SortBot.h
	$(CXX) $(CXXFLAGS) -c SortBot.cpp

clean:
	rm -f $(OBJS) myprogram