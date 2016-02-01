
PROGRAM_NAME=BankAccount


#FILE1 is always main
FILE1=main
# for other .cpp files without extention
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
	g++ -c -o ${FILE1}.o ${FILE1}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
#2	g++ -c -o ${FILE2}.o ${FILE2}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
#3	g++ -c -o ${FILE3}.o ${FILE3}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
#4	g++ -c -o ${FILE4}.o ${FILE4}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra
#5	g++ -c -o ${FILE5}.o ${FILE5}.cpp -c -fabi-version=6 -frepo -O -pedantic -std=c++11 -Wall -Wextra


#this must run...
#

link:
	g++ main.o -L ../../../usr/local/lib -o $(PROGRAM_NAME)
#2	g++ main.o $[FILE2].o -L ../../../usr/local/lib -o $(PROGRAM_NAME)
#3	g++ main.o $[FILE2].o $[FILE3].o -L ../../../usr/local/lib -o $(PROGRAM_NAME)
#4	g++ main.o $[FILE2].o $[FILE3].o $[FILE4].o -L ../../../usr/local/lib -o $(PROGRAM_NAME)
#5	g++ main.o $[FILE2].o $[FILE3].o $[FILE4].o $[FILE5].o -L ../../../usr/local/lib -o $(PROGRAM_NAME)

#
# Clean up ...
#

clean:
	rm -f *.o
	rm -f *.rpo

