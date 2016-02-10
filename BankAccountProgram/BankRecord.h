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
#include <ostream>
using std::ostream;


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
    database(const char*, const char*, char, unsigned int, unsigned int, unsigned int, float, const char*, const char*);
    ~database();
    
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
    char Get_MI();
    unsigned int Get_SSN();
    unsigned int Get_PhoneArea();
    unsigned int Get_Phone();
    float Get_Balance();
    char* Get_Account();
    char* Get_PassWd();
    
    //other functions
    friend ostream&  operator<< (ostream& os, const database& str);
};




#endif /* BankRecord_h */
