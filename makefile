#!/usr/bin makefile 


all: PrimeDivisor

PrimeDivisor: PrimeDivisor.o aliquot.o
	g++ -o PrimeDivisor PrimeDivisor.o aliquot.o

PrimeDivisor.o: PrimeDivisor.cpp
	g++ -o PrimeDivisor.o -c PrimeDivisor.cpp -W -Wall -Wno-long-long -ansi -pedantic

aliquot.o: aliquot.cpp PrimeDivisor.h
	g++ -o aliquot.o -c aliquot.cpp -W -Wall -Wno-long-long -ansi -pedantic


clean:
	rm -rf *.o

mrproper: clean
	rm -rf PrimeDivisor