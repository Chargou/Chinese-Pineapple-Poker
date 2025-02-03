CXXFLAGS=-Wall -pedantic -std=c++11 -g -Wno-sign-compare
LINK.o = $(LINK.cc)

ChinesePineapplePoker: main.o Game.o HandEvaluation.o Players.o Cards.o
	$(CXX) -o $@ $^
ChinesePineapplePokerNoEval: mainNE.o GameNE.o Players.o Cards.o
	$(CXX) -o $@ $^

doc:
	doxygen -g
	doxygen

clean:
	-rm *.o
	-rm ChinesePineapplePoker
	-rm ChinesePineapplePokerNoEval

cleano:
	-rm *.o

