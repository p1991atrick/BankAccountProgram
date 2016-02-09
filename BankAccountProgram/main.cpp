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
using std::fstream;


// Function Prototyes
int Menu(int *);
void Create_File(char *Filename);
fstream Open_File(char*);
void Set_Info(database *Record);
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
    int choice = 0;
    int *pchoice = &choice;
    char Filename[41];

    Menu(pchoice);
    switch (*pchoice)
    {
        case 1:
            Create_File(Filename);
            Set_Info(&BankRecord);
            break;
        case 2:
            //code here
            break;
        case 3:
            //code here
            break;
        default:
            return EXIT_CODE_NO_SELECTION;
            break;
    }
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

void Create_File(char *Filename)
{
    cout << "What should the database be called: ";
    char file[41]; //filename can be up to 40 char's
    strncpy(file, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 41);
    cin >> file;
    strcpy(Filename, file);
    strcat(Filename, ".db");
    fstream database(Filename, std::ios::out | std::ios::app | std::ios::binary);
    database.close();
}

void Set_Info(database *Record)
{
    //set first name
    cout << "Enter First Name: ";
    char * FNAME[30];
    cin >> *FNAME;
    Record->Set_FName(*FNAME);
    delete [] *FNAME;
    //set last name
    cout << "Enter Last Name: ";
    char * LNAME[30];
    cin >> *LNAME;
    Record->Set_LName(*LNAME);
    delete [] *LNAME;
    //set middel initial
    char MI;
    cout << "Enter Middle Initial: ";
    cin >> MI;
    Record->Set_MI(MI);
    //set ssn
    char ssn[15];
    cout << "Enter SSN (no dashes): ";
    cin >> ssn;
    Record->Set_SSN(ssn);
    //set phone area code
    
}

void Display_Output(database *Record)
{
    
}




















