#/* -----------------------------------------------------------------------------

#FILE NAME:         makefile

#DESCRIPTION:       Modular makefile for make under Linux

#MODIFICATION HISTORY:

#Author          Date           Modification(s)
#-------------   -----------    ---------------
#Patrick Kelly   01-31-2016     1.0

#----------------------------------------------------------------------------- */


PROGRAM_NAME=bankacct

# source files without extention
FILE1=main
FILE2=BankRecord
#FILE3=
#FILE4=
#FILE5=


.PHONY: build clean link all

#
# Compile ...
#

build:
    g++ -o $(FILE1).o $(FILE1).cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
    g++ -o $(FILE2).o $(FILE2).cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
#3  g++ -o $(FILE3).o $(FILE3).cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
#4  g++ -o $(FILE4).o $(FILE4).cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
#5  g++ -o $(FILE5).o $(FILE5).cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra

link:
#   g++ $(FILE1).o -L /usr/local/lib -o $(PROGRAM_NAME)
    g++ $(FILE1).o $(FILE2).o -L /usr/local/lib -o $(PROGRAM_NAME)
#3  g++ $(FILE1).o $(FILE2).o $(FILE3).o -L /usr/local/lib -o $(PROGRAM_NAME)
#4  g++ $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o -L /usr/local/lib -o $(PROGRAM_NAME)
#5  g++ $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o $(FILE5).o -L /usr/local/lib -o $(PROGRAM_NAME)



clean:
    rm *.o
    rm *.rpo