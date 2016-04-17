//
//  Command_line_Record_ .cpp
//  BankAccountProgram
//
//  Created by Gordon Freeman on 3/3/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#include "CommandLine.h"

Command_line_Record::Command_line_Record()
{
	for (int x=0;x<18;x++)
	{
		Arg_Given[x] = false;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          Command_line_Record::Set_sndAccount(char * acount)
DESCRIPTION:       sets the 2nd account number
RETURNS:           void funtion
NOTES:             contains overflow verification
----------------------------------------------------------------------------- */
void Command_line_Record::Set_scndAccount(char *acount)
{
	strncpy(scndacct, acount, 5);
	for (int n = 0; n < 5; n++)//forces all alpha char's to upper case
	{
		if ((isalpha(scndacct[n])) && (islower(scndacct[n])))
		{
			scndacct[n] = toupper(scndacct[n]);
		}
	}
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Command_line_Record::Set_sndPassWD(char * pass)
 DESCRIPTION:       sets the 2nd account password
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
void Command_line_Record::Set_scndPassWD(char * pass)
{
	strncpy(scndpass, pass, 6);
	for (int n = 0; n < 6; n++) //forces all alpha char's to upper case
	{
		if ((isalpha(scndpass[n]) == 0) && (islower(scndpass[n] == 0)))
		{
			scndpass[n] = toupper(scndpass[n]);
		}
	}
}

char* Command_line_Record::Get_scndAccount()
{
	return scndacct;
}

char* Command_line_Record::Get_scndPassWD()
{
	return scndpass;
}

int Command_line_Record::add_acount_true()
{
	if (Arg_Given[Command_line_Record::lastname] == true && Arg_Given[Command_line_Record::firstName] == true && Arg_Given[Command_line_Record::phonearea] == true && Arg_Given[Command_line_Record::phonenumber] == true && Arg_Given[Command_line_Record::middleinitial] == true && Arg_Given[Command_line_Record::ssn] == true && Arg_Given[Command_line_Record::balance] == true && Arg_Given[Command_line_Record::account] == true && Arg_Given[Command_line_Record::password] == true)
	{
		return 1;
	}
	else
		return 0;
}

int Command_line_Record::transfer()
{
	if (Arg_Given[Command_line_Record::account] == true && Arg_Given[Command_line_Record::scndaccount] == true && Arg_Given[Command_line_Record::password] == true && Arg_Given[Command_line_Record::scndpasswd] == true && Arg_Given[Command_line_Record::balance] == true)
		return 1;
	else if (Arg_Given[Command_line_Record::account] == true && Arg_Given[Command_line_Record::scndaccount] == false && Arg_Given[Command_line_Record::password] == true && Arg_Given[Command_line_Record::scndpasswd] == false && Arg_Given[Command_line_Record::balance] == true)
		return 2;
	else
		return 0;
}
