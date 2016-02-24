//
//  BankRecord.cpp
//  BankAccountProgram
//
//  Created by Gordon Freeman on 2/2/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//
/* -----------------------------------------------------------------------------

 FILE NAME:         BankRecord.cpp

 DESCRIPTION:       class support file

 USAGE:             none

 EXAMPLES:          none

 PARAMETERS:        none

 EXIT CODES:        none

 COMPILATION:       GNU (c++11)

 NOTES:             None

 MODIFICATION HISTORY:

 Author          Date           Modification(s)
 -------------   -----------    ---------------
 Patrick Kelly   01-29-2016     Created (git source control)

 ----------------------------------------------------------------------------- */


#include "BankRecord.h"

/* -----------------------------------------------------------------------------
 FUNCTION:          Constructor
 DESCRIPTION:       basic setup for class
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------------
 FUNCTION:          overloaded Constructor
 DESCRIPTION:       adv. setup for class
 RETURNS:           none
 NOTES:
 ----------------------------------------------------------------------------- */
database::database(char* l, char* f, char mi, char * ssn, char * pa, char * ph, float bal, char * acount, char * pass)
{
#if TRACE
    std::cout << "In Overloaded Constructor\n";
#endif
    strncpy(LName, l, strlen(l));
    LName[(strlen(l)+1)] = '\0';
    strncpy(FName, f, strlen(f));
    FName[(strlen(f)+1)] = '\0';
    MI = mi;
    strncpy(SSN, ssn, 9);
    SSN[9] = '\0';
    strncpy(PhoneArea, pa, 3);
    PhoneArea[3] = '\0';
    strncpy(Phone, ph, 7);
    Phone[7] = '\0';
    Balance = bal;
    strncpy(Account, acount, 5);
    Account[5] = '\0';
    strncpy(PassWd, pass, 6);
    PassWd[6] = '\0';
}

/* -----------------------------------------------------------------------------
 FUNCTION:          Destructor
 DESCRIPTION:       remove content after use
 RETURNS:           none
 NOTES:
// ----------------------------------------------------------------------------- */
//database::~database()
//{
//#if TRACE
//    std::cout << "In Destructor\n";
//#endif  
//}

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_LName(char * l)
 DESCRIPTION:       sets last name
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_FName(char * f)
 DESCRIPTION:       sets first name
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_MI(char M)
 DESCRIPTION:       sets Middle Initial
 RETURNS:           void funtion
 NOTES:
 ----------------------------------------------------------------------------- */
void database::Set_MI(char M)
{
    MI = M;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_SSN(char * s)
 DESCRIPTION:       sets ssn number
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
void database::Set_SSN(char * s)
{
    strncpy(SSN, s, 9);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_PhoneArea(char * pa)
 DESCRIPTION:       sets phone number area code
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
void database::Set_PhoneArea(char * pa)
{
    strncpy(PhoneArea, pa, 3);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_Phone(char * phone)
 DESCRIPTION:       sets the main part of the phone number
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
void database::Set_Phone(char * phone)
{
    strncpy(Phone, phone, 7);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_Balance(float *b)
 DESCRIPTION:       sets the ballance abount
 RETURNS:           void funtion
 NOTES:
 ----------------------------------------------------------------------------- */
void database::Set_Balance(float *b)
{
    *b += .00;
    Balance = *b;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_Account(char * acount)
 DESCRIPTION:       sets the account number
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
void database::Set_Account(char * acount)
{
    strncpy(Account, acount, 5);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          database::Set_PassWD(char * pass)
 DESCRIPTION:       sets the account password
 RETURNS:           void funtion
 NOTES:             contains overflow verification
 ----------------------------------------------------------------------------- */
void database::Set_PassWD(char * pass)
{
    strncpy(PassWd, pass, 6);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* -----------------------------------------------------------------------------
 FUNCTION:          char* database::Get_LName()
 DESCRIPTION:       returns the last name
 RETURNS:           char *
 NOTES:
 ----------------------------------------------------------------------------- */
char* database::Get_LName()
{
    return LName;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          char* database::Get_FName()
 DESCRIPTION:       returns the first name
 RETURNS:           char *
 NOTES:
 ----------------------------------------------------------------------------- */
char* database::Get_FName()
{
    return FName;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          char database::Get_MI()
 DESCRIPTION:       returns the middle initial
 RETURNS:           char *
 NOTES:
 ----------------------------------------------------------------------------- */
char database::Get_MI()
{
    return MI;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          char* database::Get_SSN()
 DESCRIPTION:       returns the ssn number
 RETURNS:           char *
 NOTES:
 ----------------------------------------------------------------------------- */
char* database::Get_SSN()
{
    return SSN;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          char* database::Get_PhoneArea()
 DESCRIPTION:       returns the phone number area code
 RETURNS:           char *
 NOTES:
 ----------------------------------------------------------------------------- */
char* database::Get_PhoneArea()
{
    return PhoneArea;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          char* database::Get_Phone()
 DESCRIPTION:       returns the main phone number
 RETURNS:           char *
 NOTES:
 ----------------------------------------------------------------------------- */
char* database::Get_Phone()
{
    return Phone;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          float database::Get_Balance()
 DESCRIPTION:       returns the account ballance
 RETURNS:           float
 NOTES:
 ----------------------------------------------------------------------------- */
float database::Get_Balance()
{
    return Balance;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          char* database::Get_Account()
 DESCRIPTION:       returns the account number
 RETURNS:           char *
 NOTES:
 ----------------------------------------------------------------------------- */
char* database::Get_Account()
{
    return Account;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          char* database::Get_PassWd()
 DESCRIPTION:       returns the account password
 RETURNS:           char *
 NOTES:
 ----------------------------------------------------------------------------- */
char* database::Get_PassWd()
{
    return PassWd;
}


/* -----------------------------------------------------------------------------
 FUNCTION:          void database::databaseclear()
 DESCRIPTION:       clears varables
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void database::databaseclear()
{
    *LName = NULL;
    *FName = NULL;
    MI = NULL;
    *SSN = NULL;
    *PhoneArea = NULL;
    *Phone = NULL;
    Balance = NULL;
    *Account = NULL;
    *PassWd = NULL;
}





























