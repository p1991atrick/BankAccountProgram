//
//  BankRecord.h
//  BankAccountProgram
//
//  Created by Gordon Freeman on 2/2/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#ifndef BankRecord_h
#define BankRecord_h

#include <stdio.h>

class database{
    char LName[25];
    char FName[25];
    char MI;
    unsigned int SSN;
    unsigned int PhoneArea;
    unsigned int Phone;
    double Balance;
    unsigned int Account;
    char PassWd[21];
public:
    database();
    database(char*, char*, char, unsigned int, unsigned int, unsigned int, double, unsigned int, char*);
    ~database();
    
    //set var functions//
    void Set_LName(char *);
    void Set_FName(char *);
    void Set_MI(char);
    void Set_SSN(unsigned int);
    void Set_PhoneArea(unsigned int);
    void Set_Phone(unsigned int);
    void Set_Balance(double);
    void Set_Account(unsigned int);
    void Set_PassWD(char *);
    
    //get var functions//
    
    
};




#endif /* BankRecord_h */
