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

//namespace callouts
using std::cout;
using std::endl;
using std::cin;
using std::fstream;

// Function Prototyes
int Menu(int *);
int File_IO(fstream *, char *Filename);
void Create_File(char *Filename, std::__1::fstream *);
void Open_File(char*, std::__1::fstream *);
void Save_db(database *, std::__1::fstream *);
void Set_Info(database *Record, char *);
void Display_Database(database *, char * Filename);
void Print_Output(database *);
void Print_title();
void Print_Body(database *Record);

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
    char Filename[41] = "a";
    fstream databasefile;

    //choose what to do with the file
    *pchoice = File_IO(&databasefile, Filename);

    int x=0;
    do{
        Menu(pchoice);
        switch (*pchoice)
        {
            case 1:
                Set_Info(&BankRecord, Filename);
                Save_db(&BankRecord, &databasefile);
                break;
            case 2:
                Display_Database(&BankRecord, Filename);
                break;
            case 3:

            case 5:
                return EXIT_CODE_SUCCESS;
                break;
            default:
                return EXIT_CODE_NO_SELECTION;
                break;
        }
        *pchoice = 0;
    }while (x==0);
    return EXIT_CODE_NO_SELECTION;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          menu()
 DESCRIPTION:       displays options and lets user choose
 RETURNS:           int of choice
 NOTES:
 ----------------------------------------------------------------------------- */
int Menu(int *pchoice)
{
    if (*pchoice == 0)
    {
        cout << std::setw(30) << std::right << "Bank Account Database\n\n";
        cout << std::setw(5) << std::left << "1";
        cout << "Add Accounts to a database\n";
        cout << std::setw(5) << "2";
        cout << "Remove account from database\n";
        cout << std::setw(5) << "3";
        cout << "Print database to file\n";
        cout << std::setw(5) << "4";
        cout << "Transfer betwwen accounts\n";

        //escape option
        cout << std::setw(5) << "5";
        cout << "Exit\n";

        cout << "\nWhat is your Choice: ";
        cin >> *pchoice;
        while (*pchoice < 1 || *pchoice > 5)
        {
            cout << "\n Not A valid choice.\nPlease pick from the list above.\nWhat is your Choice: ";
            cin >> *pchoice;
        }
    }
    return *pchoice;
}

int File_IO(fstream *databasefile, char *Filename)
{
    cout << "1. Create Database File\n";
    cout << "2. Open Database File\n";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "You must pick a valid choice\nEnter Choice: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        Create_File(Filename, databasefile);
        return 1;
    }
    else
    {
        Open_File(Filename, databasefile);
        return 0;
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Create_File()
 DESCRIPTION:       Creates a file with user defined name
 RETURNS:           void function
 NOTES:             Creates file with record count of 0
 ----------------------------------------------------------------------------- */
void Create_File(char *Filename, fstream *file)
{
    cout << "What should the database be called: ";
    cin >> Filename;
    if (strcmp(Filename, ".db") > 0)
    {
        strncat(Filename, ".db", 3);
    }
    cout << "Creating database file called \"" << Filename << "\", and overwriting any existing file of the same name\n";
    file->open(Filename, std::ios::out | std::ios::in | std::ios::trunc);
}


void Open_File(char *Filename, fstream *file)
{
    cout << "What is the name of the current database file: ";
    cin >> Filename;
    if (strcmp(Filename, ".db") > 0)
    {
        strncat(Filename, ".db", 3);
    }
    file->open(Filename, std::ios::in | std::ios::out | std::ios::app);
    if (file->fail())
    {
        cout << "File Not Found\n";
        exit(EXIT_CODE_FILE_IO);
    }
    else
    {
        cout << "File opened\n";
    }
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
    while (islower(MI) || isnumber(MI) || !isalpha(MI))
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
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Save_db()
 DESCRIPTION:       saves class to file
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Save_db(database *BRecord, fstream *file)
{
    //save class to file in binary mode
//    file BRecord->Get_LName() << endl;
}


/* -----------------------------------------------------------------------------
 FUNCTION:          Display_Database(database *Record, char * Filename)
 DESCRIPTION:       prints database to screen for viewing.
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Display_Database(database *Record, char * Filename)
{
    cout << std::setw(30) << "Current Bank Records\n\n";
    fstream report(Filename, std::ios::in | std::ios::binary);
    if (report.fail())
    {
        cout << "File Not Found\n";
        exit(EXIT_CODE_FILE_IO);
    }
    else
    {
        cout << "File opened\n";
    }

    Print_title();
    //loop for amount of records
    do{
//        report.read(reinterpret_cast<char *>(&Record), sizeof(Record));
        Print_Body(Record);
    }while (report.eof() == 0);

}


/* -----------------------------------------------------------------------------
 FUNCTION:          Print_title()
 DESCRIPTION:       write the header lables to the report file
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Print_title()
{
    //1st line
    cout << std::setw(12) << std::left << "Account" << std::setw(20) << "Last" << std::setw(20) << "First" << std::setw(6) << "MI" << std::setw(13) << "SS"     << std::setw(16) << "Phone"  << std::setw(15) << "Account" << endl;
    //2nd line
    cout << std::setw(12) << std::left << "Number"   << std::setw(20) << "Name" << std::setw(20) << "Name"  << std::setw(6) << "  " << std::setw(13) << "Number" << std::setw(16) << "Number" << std::setw(15) << "Balance" << endl;
    //3rd line
    cout << std::setw(12) << "--------" << std::setw(20) << "----" << std::setw(20) << "-----" << std::setw(6) << "--" << std::setw(13) << "------" << std::setw(16) << "------" << std::setw(15) << "------" << endl;
}

void Print_Body(database *Record)
{
    cout << std::setw(10) << std::left << Record->Get_Account() << std::setw(20) << Record->Get_LName() << std::setw(20) << Record->Get_FName()
    << std::setw(5) << Record->Get_MI() << std::setw(15) << Record->Get_SSN() << std::setw(15) << "(" << Record->Get_PhoneArea() << ")" << Record->Get_Phone()
    << std::setw(15) << std::right << Record->Get_Balance() << endl;
}


















