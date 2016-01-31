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
# FOR Bank Account Program

PROGRAM_NAME=Bank_Account
CC=g++
INCUDES = Includes/

.PHONY: all clean

#
# Compile and link ...
#

all:
	@echo
	@echo
    ${CC} -c -o main.o main.cpp -c -I${INCLUDES} -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
	@echo
	@echo
    ${CC} main.o -L ../../../usr/local/lib -o ${PROGRAM_NAME}
	@echo
	@echo

#
# Clean up ...
#

clean:
	rm -f *.o
	rm -f *.rpo

