//
//  BankRecord.cpp
//  BankAccountProgram
//
//  Created by Gordon Freeman on 2/2/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#include "BankRecord.h"

database::database()
{
#if TRACE
    std::cout << "In Constructor\n";
#endif
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

database::database(const char* l, const char* f, char mi, unsigned int ssn, unsigned int pa, unsigned int ph, float bal, const char * acount, const char * pass)
{
#if TRACE
    std::cout << "In Overloaded Constructor\n";
#endif
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
#if TRACE
    std::cout << "In Destructor\n";
#endif
    
    
}

void database::Set_LName(char * l)
{
    if (strlen(l) > 1 && strlen(l) < 21)//check for char count to prevent overflow
    {
        strncpy(LName, l, strlen(l));
    }
    else
    {
        strncpy(LName, l, 20);
    }
}

void database::Set_FName(char * f)
{
    if (strlen(f) > 1 && strlen(f) < 21)//check for char count to prevent overflow
    {
        strncpy(FName, f, strlen(f));
    }
    else
    {
        strncpy(FName, f, 20);
    }
}

void database::Set_MI(char M)
{
    MI = M;
}

void database::Set_SSN(char * s)
{
        SSN = atoi(s);//converts string to int
}

void database::Set_PhoneArea(char * pa)
{
    PhoneArea = atoi(pa);
}

void database::Set_Phone(char * phone)
{
    Phone = atoi(phone);
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

char* database::Get_FName()
{
    return FName;
}

char database::Get_MI()
{
    return MI;
}

unsigned int database::Get_SSN()
{
    return SSN;
}

unsigned int database::Get_PhoneArea()
{
    return PhoneArea;
}

unsigned int database::Get_Phone()
{
    return Phone;
}

float database::Get_Balance()
{
    return Balance;
}

char* database::Get_Account()
{
    return Account;
}

char* database::Get_PassWd()
{
    return PassWd;
}

































