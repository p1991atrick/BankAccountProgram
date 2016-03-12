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

#include "BankRecord.h"
#include "CLI_Bool.h"
#include "main.h"


//verbose define
int threshold = 4;
mystreambuf nostreambuf;
std::ostream nocout(&nostreambuf);


/* -----------------------------------------------------------------------------
 FUNCTION NAME:     main()
 PURPOSE:           To control flow of the program
 RETURNS:           0, or error
 NOTES:
 ----------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
    char Filename[41] = "a"; char Reportname[41] = "BankAcct.Rpt"; //create and initialize Filenames with 'a'
    fstream databasefile; //for database file
	CLI *bools = new CLI;	//for the true/false bool checks and CLI char*'s
	if (argc < 2)
	{
		CLI_Help();
		exit (EXIT_CODE_NO_SELECTION);
	}
	CLI_Args(argc, argv, Filename, Reportname, bools);
	if (bools->filename == false)
	{
		return EXIT_CODE_FILE_IO;
	}
	Record_Sort(bools, &databasefile, Filename, Reportname);
	return EXIT_CODE_SUCCESS;
}

/* -----------------------------------------------------------------------------
 FUNCTION NAME:     void CLI_Args(int argc, char *argv[], char *Filename, char *Reportname, fstream *databasefile, database *CLI_Record, CLI *bools)
 PURPOSE:           controls how the cli's are processed
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void CLI_Args(int argc, char *argv[], char *Filename, char *Reportname, CLI *bools)
{//find cli vars
	for (int i = 1; i < argc; i++)
	{
		char *arg = argv[i]; //set the next argument in line to be tested

		if (arg[0] != '/') //verifies that the initilize arg was called
		{
			CLI_Help();
			exit (EXIT_CODE_CLI_ERROR+19);
		}
	//now look for given args
		if (strcmp(arg+1, "?") == 0)//find if help is called
		{
			CLI_Help();
			exit(EXIT_CODE_SUCCESS); //displaying Help always quits program
		}
		else if (strncmp(arg+1, "A", 1) == 0) //find if phone number area code is called
		{
			if(strlen(arg+2) == 3) //lenght of the area code passed in, if not 3 fail
			{
				bools->phonearea = true;
				bools->Set_PhoneArea(arg+2);
			}
			else
			{
				log(3) << "No valid area code for phone number is not given, or not enough numbers.\n";
				exit(EXIT_CODE_CLI_ERROR);
			}
		}
		else if (strncmp(arg+1, "D", 1) == 0)//find if database file is called
		{
			strncpy(Filename, arg+2, strlen(arg));
			if(!(sizeof(Filename) > 1)) // if string is not greater then 1 == fail
				exit(EXIT_CODE_CLI_ERROR+1);
			bools->filename = true;
		}
		else if (strncmp(arg+1, "F", 1) == 0)//find if first name is called
		{
			if (strlen(arg+2) >1)
			{
				bools->Set_FName(arg+2);
				bools->firstName = true;
			}
			else
			{
				log(3) << "No valid name given.\n";
				exit(EXIT_CODE_CLI_ERROR+2);
			}
		}
		else if (strncmp(arg+1, "H", 1) == 0)//find if Phone Number is called
		{
			if(strlen(arg+2) == 7)
			{
				bools->Set_Phone(arg+2);
				bools->phonenumber = true;
			}
			else
			{
				log(3) << "No valid phone number given.\n";
				exit(EXIT_CODE_CLI_ERROR+3);
			}

		}
		else if (strncmp(arg+1, "I", 1) == 0)// print info to screen
		{
			bools->info = true;
			if (argc > 3)
				exit(EXIT_CODE_CLI_ERROR+15);
		}
		else if (strncmp(arg+1, "L", 1) == 0)//find if Last Name is called
		{
			if (strlen(arg+2) >1)
			{
				bools->Set_LName(arg+2);
				bools->lastname = true;
			}
			else
			{
				log(3) << "No vaild last name given.\n";
				exit(EXIT_CODE_CLI_ERROR+4);
			}
		}
		else if (strncmp(arg+1, "M", 1) == 0)//find if Middle initial is called
		{
			if (strlen(arg+2) == 1 && isalpha(*arg+2)) //check for length
			{
				bools->Set_MI(char(*arg+2));
				bools->middleinitial = true;
			}
			else
			{
				log(3) << "No valid Middle initial given.\n";
				exit(EXIT_CODE_CLI_ERROR+5);
			}
		}
		else if (strncmp(arg+1, "N", 1) == 0)//find if account number is called
		{
			if (strlen(arg+2) == 5) //check for correct lenght
			{
				if (bools->account == false)
				{
					bools->Set_Account(arg+2);
					bools->account = true;
				}
				else
				{
					bools->Set_sndAccount(arg+2);
					bools->sndaccount = true;
				}
			}
			else
			{
				log(3) << "No vaild account number given.\n";
				exit(EXIT_CODE_CLI_ERROR+6);
			}
		}
		else if (strncmp(arg+1, "P", 1) == 0) // find if password is called
		{
			if (strlen(arg+2) == 6) //check for correct lenght
			{
				if (bools->password == false)
				{
					bools->Set_PassWD(arg+2);
					bools->password = true;
				}
				else
				{
					bools->Set_sndPassWD(arg+2);
					bools->sndpasswd = true;
				}
			}
			else
			{
				log(3) << "No vaild password given.\n";
				exit(EXIT_CODE_CLI_ERROR+7);
			}
		}
		else if (strncmp(arg+1, "R", 1) == 0) // find if report file is called
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
				log(3) << "No valid report name given.\n";
				exit(EXIT_CODE_CLI_ERROR+8);	//this should never be able to run
			}
		}
		else if (strncmp(arg+1, "S", 1) == 0)
		{
			if (strlen(arg+2) == 9)
			{
				bools->Set_SSN(arg+2);
				bools->ssn = true;
			}
			else
			{
				log(3) << "No valid SSN given.\n";
				exit(EXIT_CODE_CLI_ERROR+9);
			}
		}
		else if (strncmp(arg+1, "T", 1) == 0)
		{
			if (strlen(arg+2) >= 1)
			{
				float num = atof(arg+2);
				bools->Set_Balance(&num);
				bools->balance = true;
			}
			else
			{
				log(3) << "No valid balance given.\n";
				exit(EXIT_CODE_CLI_ERROR+10);
			}
		}
		else if (strncmp(arg+1, "W", 1) == 0)
		{
			if (strlen(arg+2) == 6)
			{
				bools->Set_PassWD(arg+2);
				bools->newpassword = true;
			}
			else
			{
				log(3) << "No valid new password given.\n";
				exit(EXIT_CODE_CLI_ERROR+11);
			}
		}
		else if (strncmp(arg+1, "V", 1) == 0)
		{
			threshold = 3;
			if(!(argc > 3))
			{
				exit(EXIT_CODE_CLI_ERROR+12);
			}
		}
		else if (strncmp(arg+1, "C", 1) == 0)
		{
			bools->addaccnt = true;
			if(!(argc > 3))
			{
				exit(EXIT_CODE_CLI_ERROR+13);
			}
		}
		else if (strncmp(arg+1, "X", 1) == 0)
		{
			bools->deleaccnt = true;
			if (!(argc > 3))
			{
				exit(EXIT_CODE_CLI_ERROR+14);
			}
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
	log(5) << setw(5) << std::left << "/?" << "Shows this help menu.\n";		//39	#
	log(5) << setw(5) << "/A" << "Sets the phone number area code.\n";			//20	$
	log(5) << setw(5) << "/C" << "Add an account to database\n";				//33	$
	log(5) << setw(5) << "/D" << "The name of the database file to open.\n";	//21	#
	log(5) << setw(5) << "/F" << "Changes the First Name.\n";					//22	$
	log(5) << setw(5) << "/H" << "Changes the Phone Number.\n";					//23	$
	log(5) << setw(5) << "/I" << "Prints given record to screen.\n";			//35	$
	log(5) << setw(5) << "/L" << "Changes the Last Name.\n";					//24	$
	log(5) << setw(5) << "/M" << "Changes Middle Inital.\n";					//25	$
	log(5) << setw(5) << "/N" << "Account number.\n";							//26	#
	log(5) << setw(5) << "/P" << "Account Password.\n";							//27	#
	log(5) << setw(5) << "/R" << "Create report file with given filename. If no name is given the default is used.\n"; //28$
	log(5) << setw(5) << "/S" << "Change Social Security Number.\n";			//29	$
	log(5) << setw(5) << "/T" << "Amount to transfer between accounts.\n";		//30	$
	log(5) << setw(5) << "/W" << "Sets the new password for the account.\n";	//31	$
	log(5) << setw(5) << "/V" << "Sets verbose mode to true.\n";				//32	#
	log(5) << setw(5) << "/X" << "Removes specified account from database\n";	//34	$
}

/* -----------------------------------------------------------------------------
 FUNCTION NAME:		void Record_Sort(CLI *, database *, fstream *, char *, char *)
 PURPOSE:           loads classes into vector, and if needs to redo the output file
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void Record_Sort(CLI * bools, fstream * databasefile, char *Filename, char *Reportname)
{
	Open_File(Filename, databasefile); //all functions require that this file is opened.
	vector<database> Records(1);
	int n=-1, i = 0; // n = for do loop only  i = number of records that were opened.
	bool change_file = false;
	do{			// load file into class vector.
		i++;
		Records.resize(i);
		n++;
		Class_Load(databasefile, &Records[n]);
	}while ((*databasefile).eof() == 0); //run until end of file
	log(3) << "loaded file\n";
	databasefile->close();
	if (bools->add_acount_true() == 1) // check to see if adding account
	{
		i++;
		Records.resize(i);
		n++;
		Set_Info(bools, &Records[n]);
		change_file	= true;
	}
	else if (bools->reportfile == true)
	{
		Print_Report(Reportname, Records, &i);
	}
	else if (bools->transfer() == 1)
	{
		Funds_Transfer(Records, bools);
		change_file = true;
	}
	else if (bools->deleaccnt == true)
	{
		n = Delete_Account(Records, bools, &i);
		Records.erase(Records.begin()+n);
		change_file = true;
	}
	else
	{
		for (int x=0; x < i; x++)
		{
			database *rec = &Records[x]; //create pointer to current vector location
			if ((!strncmp(bools->Get_Account(), rec->Get_Account(), 5)) && (!strncmp(bools->Get_PassWd(), rec->Get_PassWd(), 6))) //check that account number and password match
			{
				CLI_Sort(bools, rec, &change_file);
			}
		}
	}
	if (change_file == true) //if a record was chaged, rewrite the output file
	{
		databasefile->open(Filename, ios::out | ios::trunc);
		for (int x=0; x<int(Records.size());x++)
		{
			File_Write(databasefile, &Records[x], &x);
		}
		databasefile->close();
	}
}

/* -----------------------------------------------------------------------------
 FUNCTION NAME:		void CLI_Sort(CLI *, database *, bool *)
 PURPOSE:           dictates what functions run
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void CLI_Sort(CLI *bools, database *rec, bool *change_file)
{
	if (bools->info == true) //I
	{
		Display_Database(rec);
	}
	else if (bools->firstName == true) //F
	{
		rec->Set_FName(bools->Get_FName());
		*change_file = true;
	}
	else if (bools->lastname== true) //L
	{
		rec->Set_LName(bools->Get_LName());
		*change_file = true;
	}
	else if (bools->phonearea == true) //A
	{
		rec->Set_PhoneArea(bools->Get_PhoneArea());
		*change_file	= true;
	}
	else if (bools->phonenumber == true) //H
	{
		rec->Set_Phone(bools->Get_Phone());
		*change_file = true;
	}
	else if (bools->middleinitial == true) //M
	{
		rec->Set_MI(bools->Get_MI());
		*change_file = true;
	}
	else if (bools->ssn == true)
	{
		rec->Set_SSN(bools->Get_SSN());
		*change_file = true;
	}
	else if (bools->newpassword == true)
	{
		rec->Set_PassWD(bools->Get_PassWd());
		*change_file = true;
	}
	else if (bools->addfunds == true)
	{
		float bal, *pbal = &bal;
		*pbal = rec->Get_Balance();
		*pbal += bools->Get_Balance();
		rec->Set_Balance(pbal);
		*change_file = true;
	}
}

/* -----------------------------------------------------------------------------===File IO=============================================================================================================================
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
        log(3) << Filename << " Opened Sucsessfuly\n";
    }
}

/* -----------------------------------------------------------------------------===Management options==================================================================================================================
 FUNCTION:          Set_Info()
 DESCRIPTION:       Adds data record to the class
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Set_Info(CLI *CLI_Record, database *Record)
{
	Record->Set_LName(CLI_Record->Get_LName());
	Record->Set_FName(CLI_Record->Get_FName());
	Record->Set_MI(CLI_Record->Get_MI());
	Record->Set_SSN(CLI_Record->Get_SSN());
	Record->Set_PhoneArea(CLI_Record->Get_PhoneArea());
	Record->Set_Phone(CLI_Record->Get_Phone());
	float bal = CLI_Record->Get_Balance(), *pbal = &bal;
	Record->Set_Balance(pbal);
	Record->Set_Account(CLI_Record->Get_Account());
	Record->Set_PassWD(CLI_Record->Get_PassWd());
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Display_Database(database *Record, char * Filename)
 DESCRIPTION:       prints database to screen for viewing.
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Display_Database(database *Record)
{
    log(3) << std::setw(30) << std::right << "Current Bank Record\n\n";
	//print the information to the screen
	log(5) << std::setw(12) << std::left << Record->Get_Account() << std::setw(20) << Record->Get_LName() << std::setw(20) << Record->Get_FName()
	<< std::setw(6) << Record->Get_MI() << std::setw(13) << Record->Get_SSN() << "(" << Record->Get_PhoneArea() << ")" << std::setw(11) << Record->Get_Phone()
	<< std::setw(12) << std::right << std::setprecision(2) << std::fixed << Record->Get_Balance() << endl;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Delete_Account(char *Filename)
 DESCRIPTION:       write the account informatoin to the screen
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
int Delete_Account(vector<database> &Records, CLI *bools, int *counter)
{
	int x=0;
	for (;x<*counter;x++)
	{
		if ((!strncmp(bools->Get_Account(), Records[x].Get_Account(), 5)) && (!strncmp(bools->Get_PassWd(), Records[x].Get_PassWd(), 6)))
		{
			return x;
		}

	}
	return -5;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void Print_File(char *Filename)
 DESCRIPTION:       prints database to report file
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void Print_Report(char *reportname, vector<database> &Records, int *i)
{

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

    //loop for #of entries
	for (int z=0; z<*i;z++)
	{
        database *Record = &Records[z];
		//        Class_Load(file, &Record);
        //body
        reportfile << std::setw(12) << std::left << Record->Get_Account() << std::setw(20) << Record->Get_LName() << std::setw(20) << Record->Get_FName()
        << std::setw(6) << Record->Get_MI() << std::setw(13) << Record->Get_SSN() << "(" << Record->Get_PhoneArea() << ")" << std::setw(11) << Record->Get_Phone()
        << std::setw(12) << std::right << std::setprecision(2) << std::fixed << Record->Get_Balance() << endl;
        
    }
    reportfile.close();
	log(3) << "Printed report file\n";
}

/* -----------------------------------------------------------------------------===Account options=====================================================================================================================
 FUNCTION:          void Funds_Transfer(char *Filename)
 DESCRIPTION:       moves funds from one account to the other.
 RETURNS:           void function
 NOTES:             has multiple points of verification.
 ----------------------------------------------------------------------------- */
void Funds_Transfer(vector<database> &Records, CLI *bools)
{
	float bal, *pbal = &bal; //temp balance holder
	int account1 = -1, account2 = -1;
	for (int n=0;n<int(Records.size());n++)
	{         //find accounts that funds are being moved
		database *Record = &Records[n];
		//       Class_Load(file, &Record);
        if (!strncmp(bools->Get_Account(), Record->Get_Account(), 5))//verify account number
        {
            if (!strncmp(bools->Get_PassWd(), Record->Get_PassWd(), 6))//verify account password
            {
				log(3) << "Found 1st account.\n";
				account1 = n;
			}
		}
		else if (!strncmp(bools->Get_sndAccount(), Record->Get_Account(), 5))//verify account number
		{
			if (!strncmp(bools->Get_sndPassWD(), Record->Get_PassWd(), 6))//verify account password
			{
				log(3) << "Found 2nd account.\n";
				account2 = n;
			}
		}
    }
    if (account1 != -1 && account2 != -1)//only runs if both accounts were found
	{
		*pbal = Records[account1].Get_Balance() - bools->Get_Balance(); //remove the funds from first account dry run
		if (*pbal < bools->Get_Balance())	//if not enough money, cancel
		{
			exit(EXIT_CODE_NO_FUNDS);
		}
		Records[account1].Set_Balance(pbal); //set the new account ballance for the first account
		*pbal = Records[account2].Get_Balance() + bools->Get_Balance(); //add funds to 2nd account
		Records[account2].Set_Balance(pbal);
		log(3) << "funds transfered.\n";
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void Funds_Remove(char *Filename)
 DESCRIPTION:       removes funds from account
 RETURNS:           void function
 NOTES:             has multiple points of verification.
 ----------------------------------------------------------------------------- */
//void Funds_Remove(char *Filename, fstream *file)
//{
//        cout << "What account will funds be withdrawn from: ";
//        cin.ignore();
//        cin.getline(account, sizeof(account), '\n'); //
//        do{
//            database Report;
//			//          Class_Load(&(*file), &Report);
//            if (!strncmp(account, Report.Get_Account(), sizeof(account))) //find account in question in the database file
//            {
//                cout << "What is the password for account " << Report.Get_Account() << ": ";
//                cin.getline(password, sizeof(password), '\n');
//                if (!strncmp(password, Report.Get_PassWd(), sizeof(password)))
//                {
//                    cout << "How much would you like to withdraw? You currently have "<< std::setprecision(2) << std::fixed << Report.Get_Balance() << ": ";
//                    cin >> *pamount;
//                    while (*pamount > Report.Get_Balance()) //loops until a valid number is found, 0 is valid
//                    {     //verify that the funds are there
//                        cout << "Not enough funds!\nNew Amount: ";
//                        cin >> *pamount;
//                    }
//                    //do the math
//                    if (*pamount > 0)
//                    {
//                        found = 1;
//                        *pamount = Report.Get_Balance() - *pamount;
//                        Report.Set_Balance(pamount);
//						//               File_Write(&databasetemp, &Report);
//                    }
//                }
//                else
//                {
//                    cout << "Incorrect password, returning to Main Menu\n";
//                }
//            }
//            else
//            {
//				//           File_Write(&databasetemp, &Report);
//            }
//        }while ((*file).eof() == 0);
//
//
//    (*file).close();
//    databasetemp.close();
//    if (found == 1) //only overwrites accounts if it sucsessfuly compleated
//    {
//        (*file).open(Filename, ios::out | ios::trunc);
//        databasetemp.open("Tempcopyfile.db", ios::in);
//        (*file).close();
//        databasetemp.close();
//    }
//}

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
			//           Class_Load(file, Report);
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
					//      File_Write(&databasetemp, Report);
                }
                else
                {
                    cout << "Incorrect password, returning to Main Menu\n";
                }
            }
            else
            {
				//     File_Write(&databasetemp, Report);
            }
        }while ((*file).eof() == 0);
    }

    (*file).close();
    databasetemp.close();
    if (found == 1) //only overwrites accounts if it sucsessfuly compleated
    {
        (*file).open(Filename, ios::out | ios::trunc);
        databasetemp.open("Tempcopyfile.db", ios::in);
        (*file).close();
        databasetemp.close();
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void File_Write(fstream *file, database *Report)
 DESCRIPTION:       saves class to file
 RETURNS:           void function
 NOTES:
 ----------------------------------------------------------------------------- */
void File_Write(fstream *file, database *Report, int *count)
{
	if(*count != 0)
	{
		(*file) << endl << endl;
	}
	(*file) << Report->Get_LName() << endl
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
 FUNCTION:          void Class_Load(fstream &databasefile, database *Report)
 DESCRIPTION:       loads information from file to class
 RETURNS:           void function
 NOTES:             loads informaition from database into class
 ----------------------------------------------------------------------------- */
void Class_Load(fstream *databasefile, database *rec)
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
    rec->Set_LName(Lname);
    rec->Set_FName(Fnmae);
	rec->Set_MI(MI);
    rec->Set_SSN(ssn);
    rec->Set_PhoneArea(Phonearea);
    rec->Set_Phone(Phone);
    rec->Set_Balance(pbal);
    rec->Set_Account(Account);
    rec->Set_PassWD(Password);
}




























