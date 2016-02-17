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
int File_IO(char *Filename);
void Create_File(char *Filename);
void Open_File(char*);
void Save_db(database, char *);
void Set_Info(database *Record, char *);
void Display_Database(char * Filename);
void Print_Output(database *);
void Print_title();
void Print_Body(database *Record);
void Delete_Account(char *);
void File_Write(fstream &databasetempfile, database *Report);
void File_Recopy(fstream &databasetempfile, char*, unsigned int counter);
void Fileload(fstream &databasefile, database *Report);

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
   // cout << sizeof(BankRecord);

    //choose what to do with the file
    *pchoice = File_IO(Filename);

    int x=0;
    do{
        Menu(pchoice);
        switch (choice)
        {
            case 1:
                Set_Info(&BankRecord, Filename);
                Save_db(BankRecord, Filename);
                break;
            case 2:
                Display_Database(Filename);
                Delete_Account(Filename);;
                break;
            case 3:

            case 5:
                //databasefile.close();
                return EXIT_CODE_SUCCESS;
                break;
            default:
                return EXIT_CODE_NO_SELECTION;
                break;
        }
        choice = 0;
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

/* -----------------------------------------------------------------------------
 FUNCTION:          File_IO(char *Filename)
 DESCRIPTION:       asks about new or saved file
 RETURNS:           int of choice
 NOTES:
 ----------------------------------------------------------------------------- */
int File_IO(char *Filename)
{
    cout << "1. Create Database File\n";
    cout << "2. Open Database File\n";
    int choice;
    cout << "Enter Choice: ";
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "You must pick a valid choice\nEnter Choice: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        Create_File(Filename);
        return 1;
    }
    else
    {
        Open_File(Filename);
        return 0;
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Create_File(char *Filename)
 DESCRIPTION:       Creates a file with user defined name
 RETURNS:           void function
 NOTES:             Creates file with record count of 0
 ----------------------------------------------------------------------------- */
void Create_File(char *Filename)
{
    cout << "What should the database be called: ";
    cin >> Filename;
    if (strcmp(Filename, ".db") > 0)
    {
        strncat(Filename, ".db", 3);
    }
    fstream databasefile(Filename, std::ios::in | std::ios::app);
    if (!databasefile.fail())
    {
        cout << "Creating database file called \"" << Filename << "\"\n";
        databasefile.close();
        databasefile.open(Filename, std::ios::out | std::ios::in | std::ios::trunc);
    }
    else
    {
        databasefile.close();
        cout << "The database with name \"" << Filename << "\" exists, Would you like to overwrite it? (y/N) \n";
        char yesno = 'N';
        cin >> yesno;
        if (yesno == 'y' || yesno == 'Y')
        {
            databasefile.open(Filename, std::ios::out | std::ios::in | std::ios::trunc);
            cout << "Creating database file called \"" << Filename << "\"\n";
        }
        else
        {
            cout << "No dabase created, as one is required the program will now exit\n";
            exit(EXIT_CODE_FILE_IO);
        }
    }
    databasefile.close();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Open_File(char *Filename)
 DESCRIPTION:       opens the file for both in and out
 RETURNS:           void function
 NOTES:             Creates file with record count of 0
 ----------------------------------------------------------------------------- */
void Open_File(char *Filename)
{
    cout << "What is the name of the current database file: ";
    fstream file;
    cin >> Filename;
    if (strcmp(Filename, ".db") > 0)
    {
        strncat(Filename, ".db", 3);
    }
    file.open(Filename, std::ios::in);
    if (file.fail())
    {
        cout << "File Not Found\n";
        exit(EXIT_CODE_FILE_IO);
    }
    else
    {
        cout << Filename << " Opened\n";
    }
    file.close();
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
    //set last name
    cout << std::setw(25) << "Enter Last Name: ";
    char LNAME[21];
    cin.ignore();
    cin.getline(LNAME, 20);
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
    //set ssn
    char ssn[11];
    cout << std::setw(25) << "Enter SSN (no dashes): ";
    cin.ignore();
    cin.getline(ssn, 10);//only takes the first 9 numbers. all others are discarded/
    //set phone area code
    char phonearea[4];
    phonearea[3] = '\0';
    cout << std::setw(25) << "Enter Phone Area Code: ";
    cin.ignore();
    cin.getline(phonearea, 4);
    //set Phone base number
    char phone[8];
    phone[7] = '\0';
    cout << std::setw(25) << "Enter Phone Number: ";
    cin.ignore();
    cin.getline(phone, 8);
    //set balance
    cout << std::setw(25) << "Enter Account Balance: ";
    float *bal;
    cin >> *bal;
    //set account number
    char accout[6];
    accout[5] = '\0';
    cout << std::setw(25) << "Enter Account Number: ";
    cin.ignore();
    cin.getline(accout, 6);
    //set account pasword
    char passwd[7];
    cout << std::setw(25) << "Enter Account Password: ";
    cin.ignore();
    cin.getline(passwd, 7);

    //write to class
    Record->Set_LName(LNAME);
    Record->Set_FName(FNAME);
    Record->Set_MI(MI);
    Record->Set_SSN(ssn);
    Record->Set_PhoneArea(phonearea);
    Record->Set_Phone(phone);
    Record->Set_Balance(bal);
    Record->Set_Account(accout);//(LNAME, FNAME, MI, ssn, phonearea, phone, bal, accout, passwd);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Save_db()
 DESCRIPTION:       saves class to file
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Save_db(database BRecord, char *Filename)
{
    //open file
    fstream databasefile(Filename, std::ios::out | std::ios::app);

    //save class to file
    databasefile << BRecord.Get_LName() << endl
    << BRecord.Get_FName() << endl
    << BRecord.Get_MI() << endl
    << BRecord.Get_SSN() << endl
    << BRecord.Get_PhoneArea() << endl
    << BRecord.Get_Phone() << endl
    << BRecord.Get_Balance() << endl
    << BRecord.Get_Account() << endl
    << BRecord.Get_PassWd() << endl << endl;

    //close file
    databasefile.close();
}


/* -----------------------------------------------------------------------------
 FUNCTION:          Display_Database(database *Record, char * Filename)
 DESCRIPTION:       prints database to screen for viewing.
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Display_Database(char * Filename)
{
    fstream databasefile(Filename, std::ios::in);//open file
    cout << std::setw(30) << std::right << "Current Bank Records\n\n";

    Print_title();//set up the header table
    char Lname[21];
    char Fnmae[21];
    char MI;
    char ssn[10];
    char Phonearea[4];
    char Phone[8];
    float Bal, *pbal = &Bal;
    char Account[6];
    char Password[7];

    //loop for amount of records
    do{
        database Record;
        databasefile >> Lname;
        Record.Set_LName(Lname);
        databasefile >> Fnmae;
        Record.Set_FName(Fnmae);
        databasefile >> MI;
        Record.Set_MI(MI);
        databasefile >> ssn;
        Record.Set_SSN(ssn);
        databasefile >> Phonearea;
        Record.Set_PhoneArea(Phonearea);
        databasefile >> Phone;
        Record.Set_Phone(Phone);
        databasefile >> *pbal;
        Record.Set_Balance(pbal);
        databasefile >> Account;
        Record.Set_Account(Account);
        databasefile >> Password;
        Print_Body(&Record);
    }while (databasefile.eof() == 0);
    //white space at end of chart
    cout << endl << endl << endl;
}


/* -----------------------------------------------------------------------------
 FUNCTION:          Print_title()
 DESCRIPTION:       Write coulum labels to screen
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Print_title()
{
    //1st line
     cout << std::setw(12) << std::left << "--------" << std::setw(20) << "-------" << std::setw(20) << "--------" << std::setw(6) << "--" << std::setw(13) << "---------" << std::setw(16) << "------------" << std::setw(15) << "-----------" << endl;
    //2nd line
    cout << std::setw(12) << std::left << "Account" << std::setw(20) << "Last" << std::setw(20) << "First" << std::setw(6) << "MI" << std::setw(13) << "SSN"     << std::setw(16) << "Phone"  << std::setw(15) << "Account" << endl;
    //3rd line
    cout << std::setw(12) << std::left << "Number"   << std::setw(20) << "Name" << std::setw(20) << "Name"  << std::setw(6) << "  " << std::setw(13) << "Number" << std::setw(16) << "Number" << std::setw(15) << "Balance" << endl;
    //4th line
    cout << std::setw(12) << "--------" << std::setw(20) << "-------" << std::setw(20) << "--------" << std::setw(6) << "--" << std::setw(13) << "---------" << std::setw(16) << "------------" << std::setw(15) << "-----------" << endl;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Print_Body()
 DESCRIPTION:       write the account informatoin to the screen
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Print_Body(database *Record)
{
    cout << std::setw(12) << std::left << Record->Get_Account() << std::setw(20) << Record->Get_LName() << std::setw(20) << Record->Get_FName()
    << std::setw(6) << Record->Get_MI() << std::setw(13) << Record->Get_SSN() << "(" << Record->Get_PhoneArea() << ")" << std::setw(11) << Record->Get_Phone()
    << std::setw(10) << std::right << std::setprecision(2) << std::fixed << Record->Get_Balance() << endl;
}


void Delete_Account(char *Filename)
{
    char accountnumber[6];
    cout << "What is the Account Number of the account you would like to delete: ";
    cin.ignore();
    cin.getline(accountnumber, 6);

    //start looking for offending account
    //vars for function
    fstream databasefile(Filename, std::ios::in);//original file
    fstream databasetempfile("Tempcopyfile.db", std::ios::out | std::ios::trunc);
    unsigned int counter = 0;
    char Lname[21];
    char Fnmae[21];
    char MI;
    char ssn[10];
    char Phonearea[4];
    char Phone[8];
    float Bal, *pbal = &Bal;
    char Account[6];
    char Password[7];
    //the brains
    do{
        database Report;
        databasefile >> Lname;
        databasefile >> Fnmae;
        databasefile >> MI;
        databasefile >> ssn;
        databasefile >> Phonearea;
        databasefile >> Phone;
        databasefile >> *pbal;
        databasefile >> Account;
        databasefile >> Password;
        if (!strcmp(accountnumber, Account))
        {
            cout << "\nDeleting accout " << accountnumber << endl;
        }
        else
        {
            Report.Set_LName(Lname);
            Report.Set_FName(Fnmae);
            Report.Set_MI(MI);
            Report.Set_SSN(ssn);
            Report.Set_PhoneArea(Phonearea);
            Report.Set_Phone(Phone);
            Report.Set_Balance(pbal);
            Report.Set_Account(Account);
            Report.Set_PassWD(Password);
            File_Write(databasetempfile, &Report);
            counter++;
        }
    }while (databasefile.eof() == 0);
    databasefile.close();
    databasetempfile.close();
    databasetempfile.open("Tempcopyfile.db", std::ios::in);
    File_Recopy(databasetempfile, Filename, counter);
    databasetempfile.close();
}

void File_Write(fstream &copyfile, database *Report)
{
    copyfile << Report->Get_LName() << endl
    << Report->Get_FName() << endl
    << Report->Get_MI() << endl
    << Report->Get_SSN() << endl
    << Report->Get_PhoneArea() << endl
    << Report->Get_Phone() << endl
    << Report->Get_Balance() << endl
    << Report->Get_Account() << endl
    << Report->Get_PassWd() << endl << endl;
}

void File_Recopy(fstream &databasetempfile, char *Filename, unsigned int counter)
{
    fstream databasefile(Filename, std::ios::out | std::ios::trunc);
    unsigned int x=1;
    do{
        database Report;
        Fileload(databasetempfile, &Report);
        File_Write(databasefile, &Report);
    }while (x < counter);
    
    databasefile.close();

}
void Fileload(fstream &databasefile, database *Report)
{
    char Lname[21];
    char Fnmae[21];
    char MI;
    char ssn[10];
    char Phonearea[4];
    char Phone[8];
    float Bal, *pbal = &Bal;
    char Account[6];
    char Password[7];
    databasefile >> Lname;
    databasefile >> Fnmae;
    databasefile >> MI;
    databasefile >> ssn;
    databasefile >> Phonearea;
    databasefile >> Phone;
    databasefile >> *pbal;
    databasefile >> Account;
    databasefile >> Password;
    Report->Set_LName(Lname);
    Report->Set_FName(Fnmae);
    Report->Set_MI(MI);
    Report->Set_SSN(ssn);
    Report->Set_PhoneArea(Phonearea);
    Report->Set_Phone(Phone);
    Report->Set_Balance(pbal);
    Report->Set_Account(Account);
    Report->Set_PassWD(Password);
}











