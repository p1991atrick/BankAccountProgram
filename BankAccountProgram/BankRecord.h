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
#include <cstring>


class database{
    char LName[21];
    char FName[21];
    char MI;
    unsigned int SSN;
    unsigned int PhoneArea;
    unsigned int Phone;
    float Balance;
    char Account[6];//length of 5 + 1
    char PassWd[7];//Length of 6+1
public:
    database();
    database(char*, char*, char, unsigned int, unsigned int, unsigned int, float, char*, char*);
    ~database();
    
    //set var functions//
    void Set_LName(char *);
    void Set_FName(char *);
    void Set_MI(char);
    void Set_SSN(unsigned int);
    void Set_PhoneArea(unsigned int);
    void Set_Phone(unsigned int);
    void Set_Balance(double);
    void Set_Account(char *);
    void Set_PassWD(char *);
    
    //get var functions//
    char* Get_LName();
    
};




#endif /* BankRecord_h */
