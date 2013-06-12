#!/usr/bin makefile 

CXX=g++
CXXFLAGS=-W -Wall -Wno-long-long -ansi -pedantic
LDFLAGS=
EXEC=PrimeDivisor



all: $(EXEC)

PrimeDivisor: PrimeDivisor.o aliquot.o
	$(CXX) -o PrimeDivisor PrimeDivisor.o aliquot.o $(LDFLAGS)

PrimeDivisor.o: PrimeDivisor.cpp
	$(CXX) -o PrimeDivisor.o -c PrimeDivisor.cpp $(CXXFLAGS)

aliquot.o: aliquot.cpp PrimeDivisor.hpp
	$(CXX) -o aliquot.o -c aliquot.cpp $(CXXFLAGS)

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf $(EXEC)