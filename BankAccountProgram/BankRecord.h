//
//  BankRecord.h
//  BankAccountProgram
//
//  Created by Gordon Freeman on 2/2/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//
/* -----------------------------------------------------------------------------

 FILE NAME:         BankRecord.h

 DESCRIPTION:       class header file

 USAGE:             none

 EXAMPLES:          none

 PARAMETERS:        none

 EXIT CODES:        none

 COMPILATION:       GNU (c++11)

 NOTES:             None

 MODIFICATION HISTORY:

 Author          Date           Modification(s)
 -------------   -----------    ---------------
 Patrick Kelly   01-29-2016     Created (under git source control)

 ----------------------------------------------------------------------------- */




#ifndef BankRecord_h
#define BankRecord_h

#include <stdio.h>
#include <cstring>
#include <iostream>
#include "My_Macros.h"


class database
{
    char LName[21];
    char FName[21];
    char MI;
    char SSN[10];
    char PhoneArea[4];
    char Phone[8];
    float Balance;
    char Account[6];//length of 5+1
    char PassWd[7];//Length of 6+1
    
public:
    //default functions
    database();
    database(char*, char*, char, char *, char *, char *, float, char*, char*);
    
    //set var functions//
    void Set_LName(char *);
    void Set_FName(char *);
    void Set_MI(char);
    void Set_SSN(char *);
    void Set_PhoneArea(char *);
    void Set_Phone(char *);
    void Set_Balance(float *);
    void Set_Account(char *);
    void Set_PassWD(char *);
    
    //get var functions//
    char* Get_LName();
    char* Get_FName();
    char Get_MI() const;
    char * Get_SSN();
    char * Get_PhoneArea();
    char * Get_Phone();
    float Get_Balance() const;
    char* Get_Account();
    char* Get_PassWd();

	//member functions
	void subtract_ball(float);

	//IO functions
	friend ostream &operator<< (ostream &stream, const database &obj);
	friend istream &operator>> (istream &stream, database &obj);
	database operator= (const database &right);
	friend fstream &operator<< (fstream &stream, const database &obj);
};


#endif /* BankRecord_h */









