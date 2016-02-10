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
void Create_File(char *Filename, database *);
void Open_File(char*);
void Save_db(database *, char *);
void Set_Info(database *Record, char *);
void Print_Output(database *);

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
    
#if TEST_CODE
    //Test function location
    
    return EXIT_CODE_PROGRAM_HALT;
    //
#endif
    
    Menu(pchoice);
    switch (*pchoice)
    {
        case 1:
            Create_File(Filename, &BankRecord);
            Set_Info(&BankRecord, Filename);
            break;
        case 2:
            Open_File(Filename);
            Set_Info(&BankRecord, Filename);
            break;
        case 3:
            Print_Output(&BankRecord);
            break;
        default:
            return EXIT_CODE_NO_SELECTION;
            break;
    }
    return EXIT_CODE_SUCCESS;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          menu()
 DESCRIPTION:       displays options and lets user choose
 RETURNS:           int of choice
 NOTES:
 ----------------------------------------------------------------------------- */
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
        cout << "What is your Choice: ";
        cin >> *pchoice;
    }while (*pchoice < 1 || *pchoice > 3);
    return *pchoice;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Create_File()
 DESCRIPTION:       Creates a file with user defined name
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Create_File(char *Filename, database *Record)
{
    cout << "What should the database be called: ";
    char *file[41]; //filename can be up to 40 char's
    cin >> *file;
    strcpy(Filename, *file);
    strcat(Filename, ".db");
    Record->count = 0;
    cout << "Creating database file called \"" << Filename << "\", and overwriting any existing file of the same name\n";
    fstream database(Filename, std::ios::out | std::ios::trunc);
    database.close();
}

void Open_File(char *Filename)
{
    cout << "What is the name of the current database file: ";
    cin >> Filename;
//    if (strstr(Filename, ".db"))
//    {
//        strcat(Filename, ".db");
//    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Set_Info()
 DESCRIPTION:       Adds data to the class
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Set_Info(database *Record, char *Filename)
{
#if TRACE
    cout << "In Set_Info\n";
#endif
    fstream database(Filename, std::ios::in | std::ios::ate);
    database >> Record->count;
    database.close();

    //increment entrie count
    Record->count++;

    //set first name
    cout << std::setw(25) << std::right << "Enter First Name: ";
    char  FNAME[21];
    cin.ignore();
    cin.getline(FNAME, 20);
    Record->Set_FName(FNAME);
    
    //set last name
    cout << std::setw(25) << "Enter Last Name: ";
    char LNAME[21];
    cin.getline(LNAME, 20);
    Record->Set_LName(LNAME);
    
    //set middel initial
    cout << std::setw(25) << "Enter Middle Initial: ";
    char MI;
    cin >> MI;
    while (islower(MI) || /*isnumber(MI) ||*/ !isalpha(MI))
    {
        cout << std::setw(25) << "Uppercase Letter ONLY\n";
        cout << std::setw(25) << "Enter Middle Initial: ";
        cin >> MI;
    }
    Record->Set_MI(MI);
    
    //set ssn
    char ssn[11];
    cout << std::setw(25) << "Enter SSN (no dashes): ";
    cin.ignore();
    cin.getline(ssn, 10);//only takes the first 9 numbers. all others are discarded/
    Record->Set_SSN(ssn);
    
    //set phone area code
    char phonearea[4];
    phonearea[3] = '\0';
    cout << std::setw(25) << "Enter Phone Area Code: ";
    cin.getline(phonearea, 4);
    Record->Set_PhoneArea(phonearea);
    
    //set Phone base number
    char phone[8];
    phone[7] = '\0';
    cout << std::setw(25) << "Enter Phone Number: ";
    cin.getline(phone, 8);
    Record->Set_Phone(phone);
    
    //set balance
    cout << std::setw(25) << "Enter Account Balance: ";
    float bal;
    float *pbal = &bal;
    cin >> *pbal;
    Record->Set_Balance(pbal);
    
    //set account number
    char accout[6];
    accout[5] = '\0';
    cout << std::setw(25) << "Enter Account Number: ";
    cin.ignore();
    cin.getline(accout, 6);
    Record->Set_Account(accout);
    
    //set account pasword
    char passwd[7];
    cout << std::setw(25) << "Enter Account Password: ";
    cin.getline(passwd, 7);
    Record->Set_PassWD(passwd);


    //save the Record to the file
    Save_db(Record, Filename);
}

void Save_db(database *BRecord, char *Filename)
{
    //save class to file in binary mode
    fstream database(Filename, std::ios::out | std::ios::app);
    database << BRecord->Get_LName() << endl
    << BRecord->Get_FName() << endl
    << BRecord->Get_MI() << endl
    << BRecord->Get_SSN() << endl
    << BRecord->Get_PhoneArea() << endl
    << BRecord->Get_Phone() << endl
    << BRecord->Get_Account() << endl
    << BRecord->Get_PassWd() << endl
    << BRecord->count << endl;
    database.close();
}


/* -----------------------------------------------------------------------------
 FUNCTION:          Print_Output()
 DESCRIPTION:       Creates a file with user defined name
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Print_Output(database *Record)
{
    
}




















