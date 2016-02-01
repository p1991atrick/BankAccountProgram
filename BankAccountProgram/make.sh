#!/bin/sh

#  make.sh
#  BankAccountProgram
#
#  Created by Patrick Kelly on 1/31/16.
#  Copyright © 2016 Patrick Kelly. All rights reserved.


#build
g++ -c -o main.o main.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
# File 2 true
if [ -z $FILE2 ]
then
    g++ -c -o ${FILE2}.o ${FILE2}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
fi
# File 3 true
if [ -z $FILE3 ]
then
    g++ -c -o ${FILE3}.o ${FILE3}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
fi
# File 4 true
if [ -z $FILE4 ]
then
g++ -c -o ${FILE4}.o ${FILE4}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
fi