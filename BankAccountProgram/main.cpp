//
//  main.cpp
//  BankAccountProgram
//
//  Created by Patrick Kelly on 1/31/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//
/* -----------------------------------------------------------------------------
 
 FILE NAME:         main.cpp
 
 DESCRIPTION:       main file for program
 
 USAGE:             no CLI args
 
 EXAMPLES:          none
 
 PARAMETERS:        none
 
 EXIT CODES:        0 = Success
                    Otherwise = Error
 
 COMPILATION:       GNU (c++11)
 
 NOTES:             None
 
 MODIFICATION HISTORY:
 
 Author          Date           Modification(s)
 -------------   -----------    ---------------
 Patrick Kelly   01-29-2016     Created (git source control)
 
 ----------------------------------------------------------------------------- */

#include <iostream>
#include "My_Macros.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>


using std::cout;
using std::endl;
using std::cin;
using std::string;

// Function Prototyes



/* -----------------------------------------------------------------------------
 FUNCTION NAME:     main()
 PURPOSE:           To control flow of the program
 RETURNS:           0, or error
 NOTES:
 ----------------------------------------------------------------------------- */
int main(/*int argc, const char * argv[]*/)
{
    
#if TRACE
    cout << "TEST\n";
#endif
    cout << "this is another test\n";
    
    
    return EXIT_CODE_SUCCESS;
}
