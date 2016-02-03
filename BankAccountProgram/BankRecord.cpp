//
//  BankRecord.cpp
//  BankAccountProgram
//
//  Created by Gordon Freeman on 2/2/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#include "BankRecord.h"
#include <ostream>

database::database()
{
    strncpy(LName, "\0", 21);
    strncpy(FName, "\0", 21);
    MI = '\0';
    SSN = 000000000;
    PhoneArea = 000;
    Phone = 0000000;
    Balance = 0.00;
    strncpy(Account, "\0", 6);
    strncpy(PassWd, "\0", 7);
}

database::database(char* l, char* f, char mi, unsigned int ssn, unsigned int pa, unsigned int ph, float bal, char * acount, char * pass)
{
    strncpy(LName, l, strlen(l));
    strncpy(FName, f, strlen(f));
    MI = mi;
    SSN = ssn;
    PhoneArea = pa;
    Phone = ph;
    Balance = bal;
    strncpy(Account, acount, 5);
    strncpy(PassWd, pass, 6);
}

database::~database()
{
}

void database::Set_LName(char * l)
{
    strncpy(LName, l, strlen(l));
}

void database::Set_FName(char * f)
{
    strncpy(FName, f, strlen(f));
}

void database::Set_MI(char M)
{
    MI = M;
}

void database::Set_SSN(unsigned int s)
{
    SSN = s;
}

void database::Set_PhoneArea(unsigned int pa)
{
    PhoneArea = pa;
}

void database::Set_Phone(unsigned int phone)
{
    Phone = phone;
}

void database::Set_Balance(double b)
{
    Balance = b;
}

void database::Set_Account(char * acount)
{
    strncpy(Account, acount, 5);
}

void database::Set_PassWD(char * pass)
{
    strncpy(PassWd, pass, 6);
}


//--------------------------------------------------------------------

char* database::Get_LName()
{
    return LName;
}



















