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

class CLI : public database
{
	char sndpass[7];
	char sndacct[6];
	
public:		//this in intentional
	bool phonearea;
	bool filename;
	bool firstName;
	bool phonenumber;
	bool info;
	bool lastname;
	bool balance;
	bool middleinitial;
	bool account;
	bool password;
	bool ssn;
	bool newpassword;
	bool reportfile;
	bool sndaccount;
	bool sndpasswd;
	bool addaccnt;
	bool deleaccnt;
	bool addfunds;
	//constructor is needed
	CLI();
	//set functions
	void Set_sndAccount(char *);
	void Set_sndPassWD(char *);

	//get functions
	char* Get_sndAccount();
	char* Get_sndPassWD();

	//member functions
	int add_acount_true();
	int transfer();
};
#endif /* CommandLine_h */

