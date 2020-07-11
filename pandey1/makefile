# File:     makefile
# Author:   Sushil pandey
# Program: Assignment1
# Date:    1/31/2019

# Description
# This makefile will make the example program of a fraction class

CC=g++
OBJECTS=main.o fraction.o decimalToFraction.o calculation.o commonFactor.o
EXE=prog1
CFLAGS=-Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o: 	main.cpp fraction.h
		$(CC) $(CFLAGS) -c main.cpp
fraction.o:	fraction.cpp fraction.h function.h
		$(CC) $(CFLAGS) -c fraction.cpp	
		
decimalToFraction.o:	decimalToFraction.cpp
		$(CC) $(CFLAGS) -c decimalToFraction.cpp
calculation.o:	calculation.cpp function.h
		$(CC) $(CFLAGS) -c calculation.cpp
commonFactor.o:	commonFactor.cpp
		$(CC) $(CFLAGS) -c commonFactor.cpp
		
clean:
		rm -rf prog *~ $(OBJECTS) $(EXE)

