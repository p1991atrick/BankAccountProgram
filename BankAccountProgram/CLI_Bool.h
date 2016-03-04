//
//  CLI_Bool.hpp
//  BankAccountProgram
//
//  Created by Gordon Freeman on 3/3/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#ifndef CLI_Bool_h
#define CLI_Bool_h

#include <stdio.h>
#include "BankRecord.h"
class CLI : public database
{
	char sndpass[6];
	char sndacct[7];
	
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
	
	//constructor is needed
	CLI();
	//functions
	void Set_sndAccount(char *);
	void Set_sndPassWD(char *);
};
#endif /* CLI_Bool_h */

