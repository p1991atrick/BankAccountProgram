# ------------------------------------------------------------------------------
#
# FILE NAME:       makefile
#
# DESCRIPTION:     Make file for a GNU program
#
# PURPOSE:         Build a program executable
#
# COMPILATION:     For use with the GNU toolset
#
# NOTES:           http://www.linuxforu.com/2012/06/gnu-make-in-detail-for-beginners/
#                  http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#                  http://www.cplusplus.com/forum/unices/12499/
#                  http://stackoverflow.com/questions/13745645/makefile-clock-skew-detected
#                  http://superuser.com/questions/112316/what-is-the-shell-command-to-display-contents-of-a-file
#                  http://www.tldp.org/HOWTO/Keyboard-and-Console-HOWTO-4.html
#
# MODIFICATION HISTORY:
#
# Author              Date          Modification(s)
# ----------------    ----------    ---------------
# Joel Fredrickson    2016-01-22    Version 0001
#
# ------------------------------------------------------------------------------

PROGRAM_NAME=BankAccount
FILE1=main
FILE2=
FILE3=
FILE4=
FILE5=


.PHONY: build link clean

#
# Compile ...
#

build:
    @echo
	@echo
	g++ -c -o main.o main.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
if [ -z $FILE2 ]
then
    g++ -c -o ${FILE2}.o ${FILE2}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
fi
if [ -z $FILE3 ]
then
    g++ -c -o ${FILE3}.o ${FILE3}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
fi

#
#this must run...
#

link:

# Only main.cpp
if [[ -z $FILE2 ]] && [[ -z $FILE3 ]] && [[ -z $FILE4 ]] && [[ -z $FILE5 ]]
then
	g++ main.o -L ../../../usr/local/lib -o $PROGRAM_NAME
fi

# Two source files
if [[ -z $FILE2 ]] && [[ -n $FILE3 ]] && [[ -n $FILE4 ]] && [[ -n $FILE5 ]]
then
    g++ main.o $[FILE2].o -L ../../../usr/local/lib -o $PROGRAM_NAME
fi

# Three source files
if [[ -z $FILE2 ]] && [[ -z $FILE3 ]] && [[ -n $FILE4 ]] && [[ -n $FILE5 ]]
then
    g++ main.o $[FILE2].o $[FILE3].o -L ../../../usr/local/lib -o $PROGRAM_NAME
fi

# Four source files
if [[ -z $FILE2 ]] && [[ -z $FILE3 ]] && [[ -z $FILE4 ]] && [[ -n $FILE5 ]]
then
    g++ main.o $[FILE2].o $[FILE3].o $[FILE4].o -L ../../../usr/local/lib -o $PROGRAM_NAME
fi

# Five source files
if [[ -z $FILE2 ]] && [[ -z $FILE3 ]] && [[ -z $FILE4 ]] && [[ -z $FILE5 ]]
then
    g++ main.o $[FILE2].o $[FILE3].o $[FILE4].o $[FILE5].o -L ../../../usr/local/lib -o $PROGRAM_NAME
fi


#
# Clean up ...
#

clean:
	rm -f *.o
	rm -f *.rpo

