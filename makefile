#!/usr/bin makefile 

CXX=g++
CXXFLAGS=-W -Wall -Wno-long-long -pedantic
LDFLAGS=
EXEC=NumDiv
#SRC=PrimeDivisor.cpp aliquot.cpp
#OBJ=$(SRC:.c=.o)

all: $(EXEC)

#NumDiv: $(OBJ)
NumDiv: PrimeDivisor.o aliquot.o 
	$(CXX) -o $@ $^ $(LDFLAGS)

aliquot.o: PrimeDivisor.hpp

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf $(EXEC)