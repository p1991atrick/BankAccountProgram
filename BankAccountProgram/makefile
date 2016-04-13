#/* -----------------------------------------------------------------------------

#FILE NAME:         makefile

#DESCRIPTION:       Modular makefile for make under Linux

#MODIFICATION HISTORY:

#Author          Date           Modification(s)
#-------------   -----------    ---------------
#Patrick Kelly   01-31-2016     X.X (under GIT source control)

#----------------------------------------------------------------------------- */


PROGRAM_NAME=bankacct

# source files without extention
FILE1=main
FILE2=BankRecord
FILE3=
FILE4=
FILE5=

ARGS=-c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra

ifndef FILE1
	exit
endif

.PHONY: build clean


build:
ifdef FILE1
	g++ -o $(FILE1).o $(FILE1).cpp $(ARGS)
endif
ifdef FILE2
	g++ -o $(FILE2).o $(FILE2).cpp $(ARGS)
endif
ifdef FILE3
	g++ -o $(FILE3).o $(FILE3).cpp $(ARGS)
endif
ifdef FILE4
	g++ -o $(FILE4).o $(FILE4).cpp $(ARGS)
endif
ifdef FILE5
	g++ -o $(FILE5).o $(FILE5).cpp $(ARGS)
endif


#1	g++ $(FILE1).o -L /usr/local/lib -o $(PROGRAM_NAME)
#2	g++ $(FILE1).o $(FILE2).o -L /usr/local/lib -o $(PROGRAM_NAME)
	g++ $(FILE1).o $(FILE2).o $(FILE3).o -L /usr/local/lib -o $(PROGRAM_NAME)
#4  g++ $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o -L /usr/local/lib -o $(PROGRAM_NAME)
#5  g++ $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o $(FILE5).o -L /usr/local/lib -o $(PROGRAM_NAME)



clean:
	rm *.o
	rm *.rpo
