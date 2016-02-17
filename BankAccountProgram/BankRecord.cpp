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
    strncpy(SSN, "\0", 10);
    strncpy(PhoneArea, "\0", 4);
    strncpy(Phone, "\0", 8);
    Balance = 0.00;
    strncpy(Account, "\0", 6);
    strncpy(PassWd, "\0", 7);
}

database::database(const char* l, const char* f, char mi, char * ssn, char * pa, char * ph, float bal, const char * acount, const char * pass)
{
#if TRACE
    std::cout << "In Overloaded Constructor\n";
#endif
    strncpy(LName, l, strlen(l));
    strncpy(FName, f, strlen(f));
    MI = mi;
    strncpy(SSN, ssn, 10);
    strncpy(PhoneArea, pa, 3);
    strncpy(Phone, ph, 7);
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
    strncpy(SSN, s, 9);
}

void database::Set_PhoneArea(char * pa)
{
    strncpy(PhoneArea, pa, 3);
}

void database::Set_Phone(char * phone)
{
    strncpy(Phone, phone, 7);
}

void database::Set_Balance(float *b)
{
    *b += .00;
    Balance = *b;
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

char* database::Get_SSN()
{
    return SSN;
}

char* database::Get_PhoneArea()
{
    return PhoneArea;
}

char* database::Get_Phone()
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

































