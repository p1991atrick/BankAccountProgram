#/* -----------------------------------------------------------------------------

#FILE NAME:         makefile

#DESCRIPTION:       Modular makefile for make under Linux

#MODIFICATION HISTORY:

#Author          Date           Modification(s)
#-------------   -----------    ---------------
#Patrick Kelly   01-31-2016     1.0

#----------------------------------------------------------------------------- */


CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp BankRecord.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bankacct

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@




