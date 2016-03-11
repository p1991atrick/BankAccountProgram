//
//  CLI_ .cpp
//  BankAccountProgram
//
//  Created by Gordon Freeman on 3/3/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#include "CLI_Bool.h"

CLI::CLI()
{
	phonenumber = false;
	phonearea = false;
	filename = false;
	firstName = false;
	lastname = false;
	info = false;
	balance = false;
	middleinitial = false;
	account = false;
	password = false;
	ssn = false;
	newpassword = false;
	reportfile = false;
	sndaccount = false;
	sndpasswd = false;
	addaccnt = false;
	deleaccnt = false;
	addfunds = false;
}

/* -----------------------------------------------------------------------------
FUNCTION:          CLI::Set_sndAccount(char * acount)
DESCRIPTION:       sets the 2nd account number
RETURNS:           void funtion
NOTES:             contains overflow verification
----------------------------------------------------------------------------- */
void CLI::Set_sndAccount(char * acount)
{
	strncpy(sndacct, acount, 5);
	for (int n = 0; n < 5; n++)//forces all alpha char's to upper case
	{
		if ((isalpha(sndacct[n])) && (islower(sndacct[n])))
		{
			sndacct[n] = toupper(sndacct[n]);
		}
	}
}

/* -----------------------------------------------------------------------------
 FUNCTION:          CLI::Set_sndPassWD(char * pass)
 DESCRIPTION:       sets the 2nd account password
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
void CLI::Set_sndPassWD(char * pass)
{
	strncpy(sndpass, pass, 6);
	for (int n = 0; n < 6; n++) //forces all alpha char's to upper case
	{
		if ((isalpha(sndpass[n]) == 0) && (islower(sndpass[n] == 0)))
		{
			sndpass[n] = toupper(sndpass[n]);
		}
	}
}

char* CLI::Get_sndAccount()
{
	return sndacct;
}

char* CLI::Get_sndPassWD()
{
	return sndpass;
}

int CLI::add_acount_true()
{
	if (lastname == true && firstName == true && phonearea == true && phonenumber == true && middleinitial == true && ssn == true && balance == true && account == true && password == true)
	{
		return 1;
	}
	else
		return 0;
}

int CLI::transfer()
{
	if (account == true && sndaccount == true && password == true && sndpasswd == true && balance == true)
		return 1;
	else if (account == true && sndaccount == false && password == true && sndpasswd == false && balance == true)
		return 2;
	else
		return 0;
}
