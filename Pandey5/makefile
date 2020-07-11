# File:     makefile
# Author:   Sushil pandey
# Program: Assignment5
# Date:    04/11/2019

# Description
# This makefile will make the example program of a Graph class


CC=g++
OBJECTS=main.o city.o
EXE=prog5
CFLAGS=-Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp graph.h 
		$(CC) $(CFLAGS) -c main.cpp 
city.o:		city.cpp
		$(CC) $(CFLAGS) -c city.cpp
clean:		
		rm -rf prog5 *~ $(OBJECTS)
