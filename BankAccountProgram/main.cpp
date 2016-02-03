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
#include <cstdlib>
#include <cstring>
#include "BankRecord.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

// Function Prototyes
int Menu(int *);
void Display_Output(database *);


/* -----------------------------------------------------------------------------
 FUNCTION NAME:     main()
 PURPOSE:           To control flow of the program
 RETURNS:           0, or error
 NOTES:
 ----------------------------------------------------------------------------- */
int main(/*int argc, const char * argv[]*/)
{
    
#if TRACE
    cout << "In Main\n";
#endif
    database BankRecord;
    int choice;
    int *pchoice = &choice;
    
    Menu(pchoice);
    
    Display_Output(&BankRecord);
    
    return EXIT_CODE_SUCCESS;
}


int Menu(int *pchoice)
{
    cout << std::setw(30) << std::right << "Bank Account Database\n\n";
    cout << std::setw(5) << std::left << "1";
    cout << "Create Database and add Accounts\n";
    cout << std::setw(5) << "2";
    cout << "Add Accounts to a database\n";
    cout << std::setw(5) << "3";
    cout << "Print database to file\n";
    do{
    cin >> *pchoice;
    }while (*pchoice < 1 || *pchoice > 3);
    return *pchoice;
}


void Display_Output(database *Record)
{
    
}




















