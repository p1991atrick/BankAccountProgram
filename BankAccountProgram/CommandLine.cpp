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
void Command_line_Record::Set_sndAccount(char *acount)
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
 FUNCTION:          Command_line_Record::Set_sndPassWD(char * pass)
 DESCRIPTION:       sets the 2nd account password
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
void Command_line_Record::Set_sndPassWD(char * pass)
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

char* Command_line_Record::Get_sndAccount()
{
	return sndacct;
}

char* Command_line_Record::Get_sndPassWD()
{
	return sndpass;
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
	if (Arg_Given[Command_line_Record::account] == true && Arg_Given[Command_line_Record::sndaccount] == true && Arg_Given[Command_line_Record::password] == true && Arg_Given[Command_line_Record::sndpasswd] == true && Arg_Given[Command_line_Record::balance] == true)
		return 1;
	else if (Arg_Given[Command_line_Record::account] == true && Arg_Given[Command_line_Record::sndaccount] == false && Arg_Given[Command_line_Record::password] == true && Arg_Given[Command_line_Record::sndpasswd] == false && Arg_Given[Command_line_Record::balance] == true)
		return 2;
	else
		return 0;
}
