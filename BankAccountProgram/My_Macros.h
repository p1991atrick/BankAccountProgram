//
//  My_Macros.h
//  Personal #include file
//
//  Created by Patrick Kelly on 8/27/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
/* -----------------------------------------------------------------------------
 
 FILE NAME:         My_Macros.h
 
 DESCRIPTION:       Macros
 
 NOTES:             None
 
 MODIFICATION HISTORY:
 
 Author          Date           Modification(s)
 -------------   -----------    ---------------
 Patrick Kelly   08-27-2015     X.X (under git control)
 
 ----------------------------------------------------------------------------- */

#ifndef My_Macros_h
#define My_Macros_h

//namespace callouts
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::ios;


//trace output
#define TRACE 0

//testing block
#define TEST_CODE 0

//clear screen for unix/linux
#define CLEAR_SCREEN system("clear");

//press anykey to continue POSIX
#define AKTC system("read -p \"Press Enter to continue...\"")

//array size calculation    total bytes/bytes of 0 location
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

//sort array #'s only. a=array  and b=size of the array
#define SORT_ARRAY_NUM(a)(b) {int swap, temp;                               \
                            do                                              \
                            {                                               \
                                swap = false;                               \
                                for (i = 0; i < (b - 1); i++)               \
                                {                                           \
                                    if (a[i] > a[i + 1])                    \
                                    {                                       \
                                        temp = a[i];                        \
                                        a[i] = a[i + 1];                    \
                                        a[i + 1] = temp;                    \
                                        swap = true;                        \
                                    }                                       \
                                }                                           \
                            } while (swap);                                 \
                            }
//find the bigger value
#define MAX(a,b) ((a) < (b) ? (b) : (a))

//exit codes
#define EXIT_CODE_SUCCESS 0
#define EXIT_CODE_FILE_IO 1
#define EXIT_CODE_ERROR_NO_MATCH_FOUND 2
#define EXIT_CODE_NO_SELECTION 3
#define EXIT_CODE_NO_FUNDS 4
#define EXIT_CODE_DOUBBLE_ENTRIE 5
#define EXIT_CODE_PROGRAM_HALT 9
#define EXIT_CODE_CLI_ERROR 20 //20-40 are reserved for CLI argumnets

#define DEBUG_OUTPUT(x) std::cout << #x << " = " << x << std::endl;

#endif /* My_Macros_h */