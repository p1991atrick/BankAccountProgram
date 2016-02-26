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
using std::ios;

// Function Prototyes
//menu
    void File_IO(char *, fstream *);
    int Main_Menu(int *);
//file IO
    void Create_File(char *, fstream *);
    void Open_File(char *, fstream *);
//management
    void Set_Info(char *, fstream *);
    void Display_Database(char *, fstream *);
    void Delete_Account(char *, fstream *);
    void Print_File(char *, fstream *);
//account
    void Funds_Transfer(char *, fstream *);
    void Funds_Add(char *,fstream *);
    void Funds_Remove(char *, fstream *);
//support functions
    void Display_title();
    void Display_Body(database *);
    void File_Write(fstream *, database *);
    void File_Recopy(fstream *, char*, fstream *);
    void Class_Load(fstream *, database *);


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
    int choice = -1, *pchoice = &choice; //initialize choice with imposible number
    char Filename[41] = "a"; //create and initialize Filename with 'a'
    int x=0; //for infinate loop
    fstream databasefile, *file = &databasefile; //for database file
    File_IO(Filename, file);
    do{ //by this point file is open for both in and out functions in binary mode
        Main_Menu(pchoice);
        switch (*pchoice)
        {
            case 1:
                Set_Info(Filename, file);
                break;
            case 2:
                Delete_Account(Filename, file);
                break;
            case 3:
                Display_Database(Filename, file);
                break;
            case 4:
                Print_File(Filename, file);
                break;
            case 5:
                Funds_Transfer(Filename, file);
                break;
            case 6:
                Funds_Add(Filename, file);
                break;
            case 7:
                Funds_Remove(Filename, file);
                break;
            case 8:
                exit(EXIT_CODE_SUCCESS);
                break;
            default: //can't ever run
                return EXIT_CODE_NO_SELECTION;
                break;
        }
        choice = -1; //reset choice back to initialize option
    }while (x==0);
    return EXIT_CODE_NO_SELECTION;
}

/* -----------------------------------------------------------------------------===Menu options===============================================
 FUNCTION:          File_IO(char *Filename)
 DESCRIPTION:       asks about new or saved file
 RETURNS:           int of choice
 NOTES:
 ----------------------------------------------------------------------------- */
void File_IO(char *Filename, fstream *file)
{
    cout << "1. Create Database File\n"; //sub menu lines
    cout << "2. Open Database File\n";
    int choice;
    cout << "Enter Choice: ";
    cin >> choice;
    while (choice < 1 || choice > 2) //verify that 1 or 2 has been entered, future proof
    {
        cout << "You must pick a valid choice\nEnter Choice: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        Create_File(Filename, file);
    }
    else
    {
        Open_File(Filename, file);
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          menu()
 DESCRIPTION:       displays options and lets user choose
 RETURNS:           int of choice
 NOTES:
 ----------------------------------------------------------------------------- */
int Main_Menu(int *pchoice)
{
    cout << std::setw(30) << std::right << "Bank Account Database\n\n";
    cout << std::setw(22) << "Management Options\n" << "--|-----------------------\n";
    cout << std::setw(3) << std::left << "1.";
    cout << "Add Account to database\n";
    cout << std::setw(3) << "2.";
    cout << "Remove account from database\n";
    cout << std::setw(3) << "3.";
    cout << "Display database\n";
    cout << std::setw(3) << "4.";
    cout << "Print report file\n";
    cout << std::setw(20) << std::right << endl << "Account Options\n" << "--|-----------------------\n";
    cout << std::setw(3) << std::left << "5.";
    cout << "Transfer funds between accounts\n";
    cout << std::setw(3) << "6.";
    cout << "Add funds to an account\n";
    cout << std::setw(3) << "7.";
    cout << "Remove funds from an account\n";

    //escape option
    cout << endl << endl;
    cout << std::setw(3) << "8.";
    cout << "Exit\n";

    cout << "\nWhat is your Choice: ";
    cin >> *pchoice;
    while (*pchoice < 1 || *pchoice > 8) //verifys that an valid option has been selected
    {
        cout << "\n Not A valid choice.\nPlease pick from the list above.\nWhat is your Choice: ";
        cin >> *pchoice;
    }
    return *pchoice; //sends the menu choice up to main for switch statement
}

/* -----------------------------------------------------------------------------===File IO=====================================================
 FUNCTION:          Create_File(char *Filename)
 DESCRIPTION:       Creates a file with user defined name
 RETURNS:           void function
 NOTES:             Creates file with record count of 0
 ----------------------------------------------------------------------------- */
void Create_File(char *Filename, fstream *file)
{
    cout << "What should the database be called: ";
    cin >> Filename;
    if (strstr(Filename, ".db") == 0) //if file name doesn't end with .db, add it
    {
        strncat(Filename, ".db", 3);
    }
    (*file).open(Filename, ios::in); //open for in ops
    if ((*file).fail())
    { //if not already there, build
        cout << "Creating database file called \"" << Filename << "\"\n";
        (*file).close();
        (*file).open(Filename, ios::out);
        Set_Info(Filename, file);
    }
    else
    { //if exists ask to open or replace
        (*file).close();
        cout << "The database with name \"" << Filename << "\" exists, Would you like to overwrite it? (y/N) \n";
        char yesno = 'N';
        cin >> yesno;
        if (yesno == 'y' || yesno == 'Y') //if told to overwrie file
        {
            (*file).open(Filename, ios::out | ios::trunc);
            cout << "Creating database file called \"" << Filename << "\"\n";
            Set_Info(Filename, file);
        }
        else //anything else opens the file
        {
            cout << "Opening File" << Filename << ".";
            (*file).open(Filename, ios::out | ios::app);
        }
    }
    (*file).close();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Open_File(char *Filename)
 DESCRIPTION:       opens the file for both in and out
 RETURNS:           void function
 NOTES:             Creates file with record count of 0
 ----------------------------------------------------------------------------- */
void Open_File(char *Filename, fstream *file)
{
    cout << "What is the name of the current database file: ";
    cin >> Filename;
    if (strstr(Filename, ".db") == 0) //if name given does't have .db , append it to the end
    {
        strncat(Filename, ".db", 3);
    }
    (*file).open(Filename, ios::in);
    if ((*file).fail()) //checks if file was found
    {
        cout << "File Not Found\nExiting\n";
        exit(EXIT_CODE_FILE_IO);    //exits program if file not found
    }
    else
    {
        (*file).close();
        cout << Filename << " Opened Sucsessfuly\n\n";
        (*file).open(Filename, ios::out | ios::app);
    }
    (*file).close();
}

/* -----------------------------------------------------------------------------===Management options===========================================
 FUNCTION:          Set_Info()
 DESCRIPTION:       Adds data to the class
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Set_Info(char *Filename, fstream *file)
{
#if TRACE
    cout << "In Set_Info\n";
#endif
    //set first name
    cout << std::setw(25) << std::right << "Enter First Name: ";
    char  FNAME[21];
    cin.ignore();
    cin.getline(FNAME, sizeof(FNAME), '\n');
    //set last name
    cout << std::setw(25) << "Enter Last Name: ";
    char LNAME[21];
    cin.getline(LNAME, sizeof(LNAME), '\n');
    //set middel initial
    cout << std::setw(25) << "Enter Middle Initial: ";
    char MI;
    cin >> MI;
    if (islower(MI))
    {
        MI = toupper(MI);
    }
    while (islower(MI) || isdigit(MI) || !isalpha(MI))
    {
        cout << std::setw(25) << "Uppercase Letter ONLY\n";
        cout << std::setw(25) << "Enter Middle Initial: ";
        cin >> MI;
    }
    //set ssn
    char ssn[11];
    cout << std::setw(25) << "Enter SSN (no dashes): ";
    cin.ignore();
    cin.getline(ssn, 11, '\n');//only takes the first 9 numbers. all others are discarded/
    //set phone area code
    char phonearea[4];
    cout << std::setw(25) << "Enter Phone Area Code: ";
    cin.getline(phonearea, sizeof(phonearea), '\n');
    //set Phone base number
    char phone[8];
    cout << std::setw(25) << "Enter Phone Number: ";
    cin.getline(phone, sizeof(phone), '\n');
    //set balance
    cout << std::setw(25) << "Enter Account Balance: ";
    float *bal;
    cin >> *bal;
    //set account number
    char accout[6];
    accout[5] = '\0';
    cout << std::setw(25) << "Enter Account Number: ";
    cin.ignore();
    cin.getline(accout, 6, '\n');
    //set account pasword
    char passwd[7];
    cout << std::setw(25) << "Enter Account Password: ";
    cin.getline(passwd, 7, '\n');

    //write to class
    database Record(LNAME, FNAME, MI, ssn, phonearea, phone, *bal, accout, passwd);
    //save to file
    (*file).open(Filename, ios::out | ios::app);
    File_Write(file, &Record);
    (*file).close();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Display_Database(database *Record, char * Filename)
 DESCRIPTION:       prints database to screen for viewing.
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Display_Database(char * Filename, fstream *file)
{
    (*file).open(Filename, ios::in);
    cout << std::setw(30) << std::right << "Current Bank Records\n\n";

    Display_title();//set up the header table

    //loop for amount of records
    do{
        database Record;
        Class_Load(file, &Record);
        Display_Body(&Record);
    }while ((*file).eof() == 0);
    //white space at end of chart
    cout << endl << endl;
    (*file).close();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Delete_Account(char *Filename)
 DESCRIPTION:       write the account informatoin to the screen
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Delete_Account(char *Filename, fstream *file)
{
    char accountnumber[6];
    char accountpassword[7];
    cout << "What is the Account Number of the account you would like to delete: ";
    cin.ignore();
    cin.getline(accountnumber, sizeof(accountnumber), '\n');//gets line until the point where enter was pressed
    cout << "What is the Account Password: ";
    cin.getline(accountpassword, sizeof(accountpassword), '\n');//gets line until the point where enter was pressed

    //start looking for offending account
    fstream databasetemp;
    (*file).open(Filename, ios::in);//load database
    databasetemp.open("Tempcopyfile.db", ios::out | ios::trunc);//temp file for new information

    //the brains
    do{
        database Report; //create report class
        Class_Load(file, &Report); //load first report from file
        if (!strcmp(accountnumber, Report.Get_Account())) //checks for matching account number
        {
            if (!strcmp(accountpassword, Report.Get_PassWd())) //check for matching account password
            {
                cout << "\nDeleting accout " << accountnumber << endl; //if both are true, do nothing.
            }
            else //if password is wrong ask for it again
            {
                cout << "Incorrect password!\n";
                cout << "What is the password for account " << accountnumber << ": ";
                cin.getline(accountpassword, 7);
                if (!strcmp(accountpassword, Report.Get_PassWd()))
                {
                    cout << "\nDeleting accout " << accountnumber << endl;
                }
                else
                {
                    cout << "To many wrong atempts, returning to menu";
                    File_Write(&databasetemp, &Report);
                }

            }
        }
        else
        {
            File_Write(&databasetemp, &Report);
        }
    }while ((*file).eof() == 0);
    databasetemp.close();
    (*file).close();
    (*file).open(Filename, ios::out | ios::trunc); //reopen database file and truncate it
    databasetemp.open("Tempcopyfile.db", ios::in);
    File_Recopy(&databasetemp, Filename, file);
    databasetemp.close(); //closes the temp file.
    (*file).close();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void Print_File(char *Filename)
 DESCRIPTION:       prints database to report file
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Print_File(char *Filename, fstream *file)
{
    //change file name
    cout << "Filename is \"BankAcct.Rpt\".\nDo you want to change it (y/n): ";
    char yesno = 'N';
    char reportname[26];
    strncpy(reportname, "BankAcct.Rpt", 13);
    cin >> yesno;
    if (yesno == 'Y' || yesno == 'y')
    {
        cout << "Enter new name without extention: ";
        cin.ignore();
        cin.getline(reportname, 20); //only the first 20 char's will be used.
        strncat(reportname, ".Rpt", 4); //add .Rpt to filename
    }
    fstream reportfile(reportname, std::ios::out); //report file

    //header
    //1st line
    reportfile << std::setw(12) << std::left << "--------" << std::setw(20) << "-------" << std::setw(20) << "--------" << std::setw(6) << "--" << std::setw(13) << "---------" << std::setw(16) << "------------" << std::setw(15) << "------------" << endl;
    //2nd line
    reportfile << std::setw(12) << std::left << "Account"  << std::setw(20) << "Last" << std::setw(20)    << "First" << std::setw(6)    << "MI" << std::setw(13) << "SSN"       << std::setw(16) << "Phone"        << std::setw(15) << "Account"     << endl;
    //3rd line
    reportfile << std::setw(12) << std::left << "Number"   << std::setw(20) << "Name" << std::setw(20)    << "Name"  << std::setw(6)    << "  " << std::setw(13) << "Number"    << std::setw(16) << "Number"       << std::setw(15) << "Balance"     << endl;
    //4th line
    reportfile << std::setw(12) << std::left << "--------" << std::setw(20) << "-------" << std::setw(20) << "--------" << std::setw(6) << "--" << std::setw(13) << "---------" << std::setw(16) << "------------" << std::setw(15) << "------------" << endl;

    (*file).open(Filename, ios::in);
    //loop for #of entries
    do{
        database Record;
        Class_Load(file, &Record);
        //body
        reportfile << std::setw(12) << std::left << Record.Get_Account() << std::setw(20) << Record.Get_LName() << std::setw(20) << Record.Get_FName()
        << std::setw(6) << Record.Get_MI() << std::setw(13) << Record.Get_SSN() << "(" << Record.Get_PhoneArea() << ")" << std::setw(11) << Record.Get_Phone()
        << std::setw(12) << std::right << std::setprecision(2) << std::fixed << Record.Get_Balance() << endl;
    }while ((*file).eof() == 0);
    reportfile.close();
    (*file).close();
}

/* -----------------------------------------------------------------------------===Account options==============================================
 FUNCTION:          void Funds_Transfer(char *Filename)
 DESCRIPTION:       moves funds from one account to the other.
 RETURNS:           void function
 NOTES:             has multiple points of verification.
 ----------------------------------------------------------------------------- */
void Funds_Transfer(char *Filename, fstream *file)
{   //vars
    char account1[6];
    char account2[6];
    float amount;
    int found = 0; //for account continuity.
    float bal, *pbal = &bal;

    cout << "What account will the funds be comming from: ";
    cin.ignore();
    cin.getline(account1, 6, '\n');
    //reset read write position to begining of file
    (*file).open(Filename, ios::in);
    fstream databasetemp("Tempcopyfile.db", ios::out | ios::trunc);//temp file for new information

    do{         //finds account that funds are coming from and removes them
        database Record;
        char *passwd;
        Class_Load(file, &Record);
        if (!strcmp(account1, Record.Get_Account()))//verify account number
        {
            cout << "Found Account. What is the password for the account: ";
            cin.ignore();
            cin.getline(passwd, 6, '\n');
            if (!strcmp(passwd, Record.Get_PassWd()))//verify account password
            {
                found =1; //to allow function to continue for next if
                cout << "You have $" << std::setprecision(2) << std::fixed << Record.Get_Balance();
                cout << "How much will you be moving: ";
                cin >> amount;
                *pbal = Record.Get_Balance()-amount;
                while (*pbal < 0)//if not enough money ask for amount again
                {
                    cout << "Funds not avalible!\n";
                    cout << "Enter new amount: ";
                    cin >> amount;
                    *pbal = Record.Get_Balance()-amount;//
                }
                Record.Set_Balance(pbal);//save new funds to record
                File_Write(file, &Record);
            }
            else
            {
                cout << "Incorrect password!";
            }
        }
        else
        {
            File_Write(file, &Record);
        }
    }while ((*file).eof() == 0);// loops until end of file.

    if (found == 1)//only runs if primary account was found
    {
        cout << "What account will the funds be going to: ";
        cin.ignore();
        cin.getline(account2, 6, '\n');
        do{
            database *Record;
            Class_Load(&databasetemp, Record);
            if (!strcmp(account2, (*Record).Get_Account()))
            {
                found = 2;
            }
        }while (databasetemp.eof() == 0 || found != 2);// loops until end of file or until account is found.
    }
    else
    {
        cout << "Second account not found.\n returning to menu\n";
    }

    databasetemp.seekg(0L, ios::beg); //set read position for temp file at begining.

    if (found == 2) //only runs if both accounts were found, until this point the database file has no changes
    {
        cout << "Found second account\n";
        //move files back to databasefile
        (*file).close();
        (*file).open(Filename, ios::out | ios::trunc);//database file truncated for new information
        do {
            database Record;
            //move the money
            Class_Load(&databasetemp, &Record);//load Record from file
            if (!strcmp(account2, Record.Get_Account()))//verify find second account
            {
                float temp;
                temp = Record.Get_Balance() + *pbal;
                Record.Set_Balance(&temp);
            }
            File_Write(file, &Record);
        } while (databasetemp.eof() == 0);
    }
    databasetemp.close();
    (*file).close();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void Funds_Remove(char *Filename)
 DESCRIPTION:       removes funds from account
 RETURNS:           void function
 NOTES:             has multiple points of verification.
 ----------------------------------------------------------------------------- */
void Funds_Remove(char *Filename, fstream *file)
{
    char account[6];
    account[5] = '\0'; //null char for end of cstring
    char password[7];
    password[6] = '\0'; //null char for end of cstring
    float amount, *pamount = &amount;
    int found = 0;

    (*file).open(Filename, ios::in);
    fstream databasetemp("Tempcopyfile.db", ios::out | ios::trunc);

    if (!(*file).fail()) //only continue if file was found.
    {
        cout << "What account will funds be withdrawn from: ";
        cin.ignore();
        cin.getline(account, sizeof(account), '\n'); //
        do{
            database Report;
            Class_Load(&(*file), &Report);
            if (!strncmp(account, Report.Get_Account(), sizeof(account))) //find account in question in the database file
            {
                cout << "What is the password for account " << Report.Get_Account() << ": ";
                cin.getline(password, sizeof(password), '\n');
                if (!strncmp(password, Report.Get_PassWd(), sizeof(password)))
                {
                    cout << "How much would you like to withdraw? You currently have "<< Report.Get_Balance() << endl;
                    cout << "Amount: ";
                    cin >> *pamount;
                    while (*pamount > Report.Get_Balance()) //loops until a valid number is found, 0 is valid
                    {     //verify that the funds are there
                        cout << "Not enough funds!\nNew Amount: ";
                        cin >> *pamount;
                    }
                    //do the math
                    if (*pamount > 0)
                    {
                        found = 1;
                        *pamount = Report.Get_Balance() - *pamount;
                        Report.Set_Balance(pamount);
                        File_Write(&databasetemp, &Report);
                    }
                }
                else
                {
                    cout << "Incorrect password, returning to Main Menu\n";
                }
            }
            else
            {
                File_Write(&databasetemp, &Report);
            }
        }while ((*file).eof() == 0);
    }

    (*file).close();
    databasetemp.close();
    if (found == 1) //only overwrites accounts if it sucsessfuly compleated
    {
        (*file).open(Filename, ios::out | ios::trunc);
        databasetemp.open("Tempcopyfile.db", ios::in);
        File_Recopy(&databasetemp, Filename, file);
        (*file).close();
        databasetemp.close();
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void Funds_Add(char *Filename)
 DESCRIPTION:       adds funds to an account
 RETURNS:           void function
 NOTES:             has multiple points of verification.
 ----------------------------------------------------------------------------- */
void Funds_Add(char *Filename, fstream *file)
{
    char account[6];
    account[5] = '\0'; //null char for end of cstring
    char password[7];
    password[6] = '\0'; //null char for end of cstring
    float amount, *pamount = &amount;
    int found = 0;

    (*file).open(Filename, ios::in);
    fstream databasetemp("Tempcopyfile.db", ios::out | ios::trunc);

    if (!(*file).fail()) //only continue if file was found.
    {
        cout << "What account will funds be added to: ";
        cin.ignore();
        cin.getline(account, sizeof(account), '\n'); //
        do{
            database Report;
            Class_Load(file, &Report);
            if (!strncmp(account, Report.Get_Account(), sizeof(account))) //find account in question in the database file
            {
                cout << "What is the password for account " << Report.Get_Account() << ": ";
                cin.getline(password, sizeof(password), '\n');
                if (!strncmp(password, Report.Get_PassWd(), sizeof(password)))
                {
                    cout << "How much would you like to Deposit?\n";
                    cout << "Amount: ";
                    cin >> *pamount;
                    found = 1;
                    *pamount = Report.Get_Balance() + *pamount;
                    Report.Set_Balance(pamount);
                    File_Write(&databasetemp, &Report);
                }
                else
                {
                    cout << "Incorrect password, returning to Main Menu\n";
                }
            }
            else
            {
                File_Write(&databasetemp, &Report);
            }
        }while ((*file).eof() == 0);
    }

    (*file).close();
    databasetemp.close();
    if (found == 1) //only overwrites accounts if it sucsessfuly compleated
    {
        (*file).open(Filename, ios::out | ios::trunc);
        databasetemp.open("Tempcopyfile.db", ios::in);
        File_Recopy(&databasetemp, Filename, file);
        (*file).close();
        databasetemp.close();
    }
}

/* -----------------------------------------------------------------------------===Support Functions===========================================
 FUNCTION:          void Display_title()
 DESCRIPTION:       Write coulum labels to screen
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Display_title()
{
    //1st line
     cout << std::setw(12) << std::left << "--------" << std::setw(20) << "-------" << std::setw(20) << "--------" << std::setw(6) << "--" << std::setw(13) << "---------" << std::setw(16) << "------------" << std::setw(15) << "------------" << endl;
    //2nd line
    cout << std::setw(12) << std::left << "Account" << std::setw(20) << "Last" << std::setw(20) << "First" << std::setw(6) << "MI" << std::setw(13) << "SSN"     << std::setw(16) << "Phone"  << std::setw(15) << "Account" << endl;
    //3rd line
    cout << std::setw(12) << std::left << "Number"   << std::setw(20) << "Name" << std::setw(20) << "Name"  << std::setw(6) << "  " << std::setw(13) << "Number" << std::setw(16) << "Number" << std::setw(15) << "Balance" << endl;
    //4th line
    cout << std::setw(12) << "--------" << std::setw(20) << "-------" << std::setw(20) << "--------" << std::setw(6) << "--" << std::setw(13) << "---------" << std::setw(16) << "------------" << std::setw(15) << "------------" << endl;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void Display_Body(database *Record)
 DESCRIPTION:       write the account informatoin to the screen
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Display_Body(database *Record)
{
    cout << std::setw(12) << std::left << (*Record).Get_Account() << std::setw(20) << (*Record).Get_LName() << std::setw(20) << (*Record).Get_FName()
    << std::setw(6) << (*Record).Get_MI() << std::setw(13) << (*Record).Get_SSN() << "(" << (*Record).Get_PhoneArea() << ")" << std::setw(11) << (*Record).Get_Phone()
    << std::setw(12) << std::right << std::setprecision(2) << std::fixed << (*Record).Get_Balance() << endl;
}


/* -----------------------------------------------------------------------------
 FUNCTION:          File_Write(fstream &file, database *Report)
 DESCRIPTION:       saves class to file
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void File_Write(fstream *file, database *Report)
{
    (*file) << Report->Get_LName() << endl
    << Report->Get_FName() << endl
    << Report->Get_MI() << endl
    << Report->Get_SSN() << endl
    << Report->Get_PhoneArea() << endl
    << Report->Get_Phone() << endl
    << Report->Get_Balance() << endl
    << Report->Get_Account() << endl
    << Report->Get_PassWd() << endl << endl;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void File_Recopy(fstream &databasetempfile, char *Filename)
 DESCRIPTION:       moves information between two files
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void File_Recopy(fstream *fromfile, char *Filename, fstream *tofile)
{
    do{
        database Report; //class structure for vars
        Class_Load(fromfile, &Report); //load in values from source file
        File_Write(tofile, &Report); //write out values to destination file
    }while ((*fromfile).eof() == 0);   //do loop until end of file
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void Class_Load(fstream &databasefile, database *Report)
 DESCRIPTION:       loads information from file to class
 RETURNS:           void function
 NOTES:             loads informaition from database into class
 ----------------------------------------------------------------------------- */
void Class_Load(fstream *databasefile, database *Report)
{   //vars for temp useage
    char Lname[21];
    char Fnmae[21];
    char MI;
    char ssn[10];
    char Phonearea[4];
    char Phone[8];
    float Bal, *pbal = &Bal;
    char Account[6];
    char Password[7];
    (*databasefile) >> Lname;
    (*databasefile) >> Fnmae;
    (*databasefile) >> MI;
    (*databasefile) >> ssn;
    (*databasefile) >> Phonearea;
    (*databasefile) >> Phone;
    (*databasefile) >> *pbal;
    (*databasefile) >> Account;
    (*databasefile) >> Password;
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




























