//
//  CLI_Bool.hpp
//  BankAccountProgram
//
//  Created by Gordon Freeman on 3/3/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#ifndef CommandLine_h
#define CommandLine_h

#include <stdio.h>
#include "BankRecord.h"
#include "My_Macros.h"

class Command_line_Record : public database
{
	char scndpass[7];
	char scndacct[6];
	
public:		//this in intentional
	enum Status
	{
		phonearea,
		filename,
		firstName,
		phonenumber,
		info,
		lastname,
		balance,
		middleinitial,
		account,
		password,
		ssn,
		newpassword,
		reportfile,
		scndaccount,
		scndpasswd,
		addaccnt,
		deleaccnt,
		addfunds,
	};
	bool Arg_Given[18];
	//constructor is needed
	Command_line_Record();
	//set functions
	void Set_scndAccount(char *);
	void Set_scndPassWD(char *);

	//get functions
	char* Get_scndAccount();
	char* Get_scndPassWD();

	//member functions
	int add_acount_true();
	int transfer();
};
#endif /* CommandLine_h */

