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
 Patrick Kelly   01-29-2016     Created (under git source control)
 
 ----------------------------------------------------------------------------- */


#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "BankRecord.h"
#include "CLI_Bool.h"

//namespace callouts
using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::ios;
using std::setw;

// Function Prototyes
//menu
	void CLI_Args(int, char *argv[], char *, char *, fstream *, database *, CLI *);
	void CLI_Help();
	void CLI_Sort(CLI *, database *, fstream *, char *, char *);
//file IO
    void Create_File(char *, fstream *);
    void Open_File(char *, fstream *);
//management
    void Set_Info(char *, fstream *);
    void Display_Database(char *, fstream *, database *);
    void Delete_Account(char *, fstream *);
    void Print_File(char *, fstream *);
//account
    void Funds_Transfer(char *, fstream *);
    void Funds_Add(char *,fstream *);
    void Funds_Remove(char *, fstream *);
//support functions
    void Display_title();
    void File_Write(fstream *, database *);
    void File_Recopy(fstream *, fstream *);
    void Class_Load(fstream *, database *);

//verbose define
int threshold = 4;
class mystreambuf: public std::streambuf
{
};
mystreambuf nostreambuf;
std::ostream nocout(&nostreambuf);
#define log(x) ((x >= threshold)? std::cout : nocout)


/* -----------------------------------------------------------------------------
 FUNCTION NAME:     main()
 PURPOSE:           To control flow of the program
 RETURNS:           0, or error
 NOTES:
 ----------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
    char Filename[41] = "a"; char Reportname[41] = "a"; //create and initialize Filenames with 'a'
    fstream databasefile; //for database file
	database *CLI_Record = new database;	//for getting CLI arg's
	CLI *bools = new CLI;	//for the true/false bool checks
	log(3) << "Verbose Test\n";
	if (argc < 2)
	{
		CLI_Help();
		exit (EXIT_CODE_NO_SELECTION);
	}
	CLI_Args(argc, argv, Filename, Reportname, &databasefile, CLI_Record, bools);
	CLI_Sort(bools, CLI_Record, &databasefile, Filename, Reportname);
	return EXIT_CODE_SUCCESS;
}

/* -----------------------------------------------------------------------------
 FUNCTION NAME:     void CLI_Args(int argc, char *argv[], char *Filename, char *Reportname, fstream *databasefile, database *CLI_Record, CLI *bools)
 PURPOSE:           controls how the cli's are processed
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void CLI_Args(int argc, char *argv[], char *Filename, char *Reportname, fstream *databasefile, database *CLI_Record, CLI *bools)
{//find cli vars
	for (int i = 1; i < argc; i++)
	{
		char *arg = argv[i]; //set the next argument in line to be tested

		if (arg[0] != '/') //verifies that the initilize arg was called
		{
			CLI_Help();
			exit (EXIT_CODE_CLI_ERROR);
		}
		if (strcmp(arg+1, "?") == 0)//find if help is called
		{
			CLI_Help();
			exit(EXIT_CODE_SUCCESS); //displaying Help always quits program
		}
		if (strncmp(arg+1, "A", 1) == 0) //find if phone number area code is called
		{
			if(strlen(arg+2) == 3) //lenght of the area code passed in, if not 3 fail
			{
				CLI_Record->Set_PhoneArea(arg+2);
				bools->phonearea = true;
			}
			else
			{
				log(5) << "Area code for phone number is not given, or not enough numbers.\n";
				exit(EXIT_CODE_CLI_ERROR);
			}
		}
		if (strncmp(arg+1, "D", 1) == 0)//find if database file is called
		{
			strncpy(Filename, arg+2, strlen(arg));
			if(!(sizeof(Filename) > 1)) // if string is not greater then 1 == fail
				exit(EXIT_CODE_CLI_ERROR+1);
			bools->filename = true;
		}
		if (strncmp(arg+1, "F", 1) == 0)//find if first name is called
		{
			if (strlen(arg+2) >1)
			{
				CLI_Record->Set_FName(arg+2);
				bools->firstName = true;
			}
			else
			{
				log(5) << "Invalid name given.\n";
				exit(EXIT_CODE_CLI_ERROR+2);
			}
		}
		if (strncmp(arg+1, "H", 1) == 0)//find if Phone Number is called
		{
			if(strlen(arg+2) == 7)
			{
				CLI_Record->Set_Phone(arg+2);
				bools->phonenumber = true;
			}
			else
			{
				log(5) << "Invalid phone number given.\n";
				exit(EXIT_CODE_CLI_ERROR+3);
			}

		}
		if (strncmp(arg+1, "I", 1) == 0)// print info to screen
		{
			bools->info = true;
		}
		if (strncmp(arg+1, "L", 1) == 0)//find if Last Name is called
		{
			if (strlen(arg+2) >1)
			{
				CLI_Record->Set_LName(arg+2);
				bools->lastname = true;
			}
			else
			{
				log(5) << "No vaild last name found.\n";
				exit(EXIT_CODE_CLI_ERROR+4);
			}
		}
		if (strncmp(arg+1, "M", 1) == 0)//find if Middle initial is called
		{
			if (strlen(arg+2) >= 1) //check for length
			{
				if (isalpha(*arg+2) == true) //check for letter
				{
					CLI_Record->Set_MI(char(*arg+2));
					bools->middleinitial = true;
				}
				else
				{
					log(5) << "No valid Middle initial given.\n";
					exit(EXIT_CODE_CLI_ERROR+5);
				}
			}
			else
			{
				log(5) << "No valid Middle initial given.\n";
				exit(EXIT_CODE_CLI_ERROR+5);
			}
		}
		if (strncmp(arg+1, "N", 1) == 0)//find if account number is called
		{
			if (strlen(arg+2) == 5) //check for correct lenght
			{
				CLI_Record->Set_Account(arg+2);
				bools->account = true;
			}
			else
			{
				log(5) << "No vaild account number given.\n";
				exit(EXIT_CODE_CLI_ERROR+6);
			}
		}
		if (strncmp(arg+1, "P", 1) == 0) // find if password is called
		{
			if (strlen(arg+2) == 6) //check for correct lenght
			{
				CLI_Record->Set_PassWD(arg+2);
				bools->password = true;
			}
			else
			{
				log(5) << "No vaild password given.\n";
				exit(EXIT_CODE_CLI_ERROR+7);
			}
		}
		if (strncmp(arg+1, "R", 1) == 0) // find if report file is called
		{
			if (strlen(arg+2) == 0)
			{
				strncpy(Reportname, "BankAcct.Rpt", 13);
				bools->reportfile = true;
			}
			else if (strlen(arg+2) >= 1)
			{
				strncpy(Reportname, (arg+2), strlen(arg+2));
				bools->reportfile = true;
			}
			else
			{
				log(5) << "No valid report name given.\n";
				exit(EXIT_CODE_CLI_ERROR+8);	//this should never be able to run
			}
		}
		if (strncmp(arg+1, "S", 1) == 0)
		{
			if (strlen(arg+2) == 9)
			{
				CLI_Record->Set_SSN(arg+2);
				bools->ssn = true;
			}
			else
			{
				log(5) << "No valid SSN given.\n";
				exit(EXIT_CODE_CLI_ERROR+9);
			}
		}
		if (strncmp(arg+1, "T", 1) == 0)
		{
			if (strlen(arg+2) >= 1)
			{
				float num = atof(arg+2);
				CLI_Record->Set_Balance(&num);
				bools->balance = true;
			}
			else
			{
				log(5) << "No valid balance given.\n";
				exit(EXIT_CODE_CLI_ERROR+10);
			}
		}
		if (strncmp(arg+1, "W", 1) == 0)
		{
			if (strlen(arg+2) == 6)
			{
				CLI_Record->Set_NewPasswd(arg+2);
				bools->newpassword = true;
			}
			else
			{
				log(5) << "No valid new password given.\n";
				exit(EXIT_CODE_CLI_ERROR+11);
			}
		}
		if (strncmp(arg+1, "V", 1) == 0)
		{
			threshold = 3;
		}
	}
}

/* -----------------------------------------------------------------------------
 FUNCTION NAME:     void CLI_Help()
 PURPOSE:           displays the help screen for command line functions
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void CLI_Help()
{
	log(5) << setw(40) << std::right << "Bank Account Database Help\n\n";	//exit codes for CLI arg's failures
	log(5) << setw(5) << std::left << "/?" << "Shows this help menu.\n";		//--
	log(5) << setw(5) << "/A" << "Sets the phone number area code.\n";			//20
	log(5) << setw(5) << "/D" << "The name of the database file to open.\n";	//21
	log(5) << setw(5) << "/F" << "Set the First Name.\n";						//22
	log(5) << setw(5) << "/H" << "Sets the Phone Number.\n";					//23
	log(5) << setw(5) << "/I" << "give information to user.\n";					//--
	log(5) << setw(5) << "/L" << "Sets the Last Name.\n";						//24
	log(5) << setw(5) << "/M" << "Sets Middle Inital.\n";						//25
	log(5) << setw(5) << "/N" << "Account number.\n";							//26
	log(5) << setw(5) << "/P" << "Account Password.\n";							//27
	log(5) << setw(5) << "/R" << "Create report file with given filename. If no name is given the default is used.\n"; //28
	log(5) << setw(5) << "/S" << "Social Security Number.\n";					//29
	log(5) << setw(5) << "/T" << "Amount ???.\n";								//30
	log(5) << setw(5) << "/W" << "Sets the new password for the account.\n";	//31
	log(5) << setw(5) << "/V" << "turns on verbose mode.\n";					//32
}

/* -----------------------------------------------------------------------------
 FUNCTION NAME:		void CLI_Sort(CLI *, database *, fstream *, char *, char *)
 PURPOSE:           dictates what functions run
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void CLI_Sort(CLI * bools, database * CLI_Record, fstream * databasefile, char *Filename, char *Reportname)
{
	Open_File(Filename, databasefile); //all functions require that this file is opened.
	if (bools->filename == true && bools->account == true && bools->password == true && bools->info == true)
	{
		Display_Database(Filename, databasefile, CLI_Record);
	}
}


/* -----------------------------------------------------------------------------===File IO=============================================================================================================================
 FUNCTION:          Create_File(char *Filename)
 DESCRIPTION:       Creates a file with user defined name
 RETURNS:           void function
 NOTES:             Creates file with record count of 0
 ----------------------------------------------------------------------------- */
void Create_File(char *Filename, fstream *file)
{
    log(5) << "What should the database be called: ";
    cin >> Filename;
    if (strstr(Filename, ".db") == 0) //if file name doesn't end with .db, add it
    {
        strncat(Filename, ".db", 3);
    }
    (*file).open(Filename, ios::in); //open for in ops
    if ((*file).fail())
    { //if not already there, build
        log(5) << "Creating database file called \"" << Filename << "\"\n";
        (*file).close();
        (*file).open(Filename, ios::out | ios::trunc);
        log(5) << "Enter the first record into the database.\n\n";
        file->close();
        Set_Info(Filename, file);
    }
    else
    { //if exists ask to open or replace
        (*file).close();
        log(5) << "The database with name \"" << Filename << "\" exists, Would you like to overwrite it? (y/N) \n";
        char yesno = 'N';
        cin >> yesno;
        if (yesno == 'y' || yesno == 'Y') //if told to overwrie file
        {
            (*file).open(Filename, ios::out | ios::trunc);
            log(5) << "Creating database file called \"" << Filename << "\"\n";
            file->close();
            log(5) << "Enter the first record into the database.\n\n";
            Set_Info(Filename, file);
        }
        else //anything else opens the file
        {
            log(5) << "Opening File" << Filename << ".";
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
    if (strstr(Filename, ".db") == 0) //if name given does't have .db , append it to the end
    {
        strncat(Filename, ".db", 3);
    }
    (*file).open(Filename, ios::in);
    if ((*file).fail()) //checks if file was found
    {
        log(3) << "File Not Found\nExiting\n";
		exit(EXIT_CODE_FILE_IO);    //exits program if file not found
    }
    else
    {
        (*file).close();
        log(3) << Filename << " Opened Sucsessfuly\n\n";
        (*file).open(Filename, ios::out | ios::app);
    }
    (*file).close();
}

/* -----------------------------------------------------------------------------===Management options==================================================================================================================
 FUNCTION:          Set_Info()
 DESCRIPTION:       Adds data to the class
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Set_Info(char *Filename, fstream *file)
{
#if TRACE
    log(3) << "In Set_Info\n";
#endif
    //set first name
    cout << std::setw(25) << std::right << "Enter First Name: ";
    char  FNAME[21];
    cin.ignore();
    cin.getline(FNAME, sizeof(FNAME), '\n'); //gets all char's until the next line char. (when enter was pressed)
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
    cin.getline(ssn, sizeof(ssn), '\n');//only takes the first 9 numbers. all others are discarded/
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
    float bal, *pbal = &bal;
    cin >> *pbal;
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

    //write to class with overloaded constructor
    database Record(LNAME, FNAME, MI, ssn, phonearea, phone, *pbal, accout, passwd);
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
void Display_Database(char * Filename, fstream *file, database *CLI_Record)
{
    (*file).open(Filename, ios::in);
    cout << std::setw(30) << std::right << "Current Bank Records\n\n";

    Display_title();//set up the header table

    //loop for amount of records
    do{
        database *Record = new database;
        Class_Load(file, Record);
			if (!strncmp(CLI_Record->Get_Account(), Record->Get_Account(), 5))
			{
				cout << std::setw(12) << std::left << Record->Get_Account() << std::setw(20) << Record->Get_LName() << std::setw(20) << Record->Get_FName()
				<< std::setw(6) << Record->Get_MI() << std::setw(13) << Record->Get_SSN() << "(" << Record->Get_PhoneArea() << ")" << std::setw(11) << Record->Get_Phone()
				<< std::setw(12) << std::right << std::setprecision(2) << std::fixed << Record->Get_Balance() << endl;
			}
		delete Record;
    }while (!(*file).eof() != 0);
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
    int trace = 0; //continuity for function
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
        database Record; //create report class
        Class_Load(file, &Record); //load first report from file
        if (!strcmp(accountnumber, Record.Get_Account())) //checks for matching account number
        {
            if (!strcmp(accountpassword, Record.Get_PassWd())) //check for matching account password
            {
                cout << "\nDeleting accout " << accountnumber << endl; //if both are true, do nothing.
            }
            else //if password is wrong ask for it again
            {
                cout << "Incorrect password!\n";
                cout << "What is the password for account " << accountnumber << ": ";
                cin.getline(accountpassword, 7);
                if (!strcmp(accountpassword, Record.Get_PassWd()))
                {
                    cout << "\nDeleting accout " << accountnumber << endl;
                    trace = 1;
                }
                else
                {
                    cout << "To many wrong atempts, returning to menu";
                    File_Write(&databasetemp, &Record);
                }

            }
        }
        else
        {
            File_Write(&databasetemp, &Record);
        }
        
    }while ((*file).eof() == 0);
    databasetemp.close();
    (*file).close();
    if (trace == 1)
    {
        (*file).open(Filename, ios::out | ios::trunc); //reopen database file and truncate it
        databasetemp.open("Tempcopyfile.db", ios::in);
        File_Recopy(&databasetemp, file);
        databasetemp.close(); //closes the temp file.
        (*file).close();
    }
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
	cout << "Printed report file\n";
}

/* -----------------------------------------------------------------------------===Account options=====================================================================================================================
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
        char passwd[7];
        Class_Load(file, &Record);
        if (!strcmp(account1, Record.Get_Account()))//verify account number
        {
            cout << "Found Account. What is the password for the account: ";
            cin.getline(passwd, 7, '\n');
            if (!strcmp(passwd, Record.Get_PassWd()))//verify account password
            {
                found =1; //to allow function to continue for next if
                cout << "You have $" << std::setprecision(2) << std::fixed << Record.Get_Balance() << endl;
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
                File_Write(&databasetemp, &Record);
            }
            else
            {
                cout << "Incorrect password!";
            }
        }
        else
        {
            File_Write(&databasetemp, &Record);
        }
        
    }while ((*file).eof() == 0);// loops until end of file.
	databasetemp.close();
	databasetemp.open("Tempcopyfile.db", ios::in);
    if (found == 1)//only runs if primary account was found
    {
        cout << "What account will the funds be going to: ";
        cin.ignore();
        cin.getline(account2, 6, '\n');
        do{
            database Record;
            Class_Load(&databasetemp, &Record);
            if (!strcmp(account2, Record.Get_Account()))
            {
                found = 2;
            }
        }while (databasetemp.eof() == 0 || found != 2);// loops until end of file or until account is found.
    }
    else
    {
        cout << "\nSecond account not found.\n    Returning to menu\n";
    }

	databasetemp.close();
	databasetemp.open("Tempcopyfile.db", ios::in); //set read position for temp file at begining.

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
		cout << "Funds transfered\n";
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
                    cout << "How much would you like to withdraw? You currently have "<< std::setprecision(2) << std::fixed << Report.Get_Balance() << ": ";
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
        File_Recopy(&databasetemp, file);
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
            database *Report = new database;
            Class_Load(file, Report);
            if (!strncmp(account, Report->Get_Account(), sizeof(account))) //find account in question in the database file
            {
                cout << "What is the password for account " << Report->Get_Account() << ": ";
                cin.getline(password, sizeof(password), '\n');
                if (!strncmp(password, Report->Get_PassWd(), sizeof(password)))
                {
                    cout << "How much would you like to Deposit?\n";
                    cout << "Amount: ";
                    cin >> *pamount;
                    found = 1;
                    *pamount = Report->Get_Balance() + *pamount;
                    Report->Set_Balance(pamount);
                    File_Write(&databasetemp, Report);
                }
                else
                {
                    cout << "Incorrect password, returning to Main Menu\n";
                }
            }
            else
            {
                File_Write(&databasetemp, Report);
            }
        }while ((*file).eof() == 0);
    }

    (*file).close();
    databasetemp.close();
    if (found == 1) //only overwrites accounts if it sucsessfuly compleated
    {
        (*file).open(Filename, ios::out | ios::trunc);
        databasetemp.open("Tempcopyfile.db", ios::in);
        File_Recopy(&databasetemp, file);
        (*file).close();
        databasetemp.close();
    }
}

/* -----------------------------------------------------------------------------===Support Functions=======================================================================================================================
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
    cout << std::setw(12) <<              "--------" << std::setw(20) << "-------" << std::setw(20) << "--------" << std::setw(6) << "--" << std::setw(13) << "---------" << std::setw(16) << "------------" << std::setw(15) << "------------" << endl;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void File_Write(fstream *file, database *Report)
 DESCRIPTION:       saves class to file
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void File_Write(fstream *file, database *Report)
{
    (*file) << endl << endl
    << Report->Get_LName() << endl
    << Report->Get_FName() << endl
    << Report->Get_MI() << endl
    << Report->Get_SSN() << endl
    << Report->Get_PhoneArea() << endl
    << Report->Get_Phone() << endl
    << Report->Get_Balance() << endl
    << Report->Get_Account() << endl
    << Report->Get_PassWd();
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void File_Recopy(fstream *fromfile, fstream *tofile, int *count)
 DESCRIPTION:       moves information between two files
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void File_Recopy(fstream *fromfile, fstream *tofile)
{
    do{
        database Report; //class structure for vars
        Class_Load(fromfile, &Report); //load in values from source file
        File_Write(tofile, &Report); //write out values to destination file
    }while ((*fromfile).eof() == 0);   //do loop until end of entries
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




























