//
//  main.h
//  BankAccountProgram
//
//  Created by Gordon Freeman on 3/5/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#ifndef main_h
#define main_h


extern int threshold;

class mystreambuf: public std::streambuf
{
};

#define log(x) ((x >= threshold)? std::cout : nocout)

#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

//namespace callouts
using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::ios;
using std::setw;
using std::vector;

// Function Prototyes
//menu
void CLI_Args(int, char *argv[], char *, char *, CLI *);
void CLI_Help();
void Record_Sort(CLI *, fstream *, char *, char *);
void CLI_Sort(CLI *, database *, bool *, char *);
//file IO
void Open_File(char *, fstream *);
//management
void Set_Info(CLI *, database *);
void Display_Database(CLI *, database *);
void Delete_Account(char *, fstream *);
void Print_Report(char *, vector<database> &, int *);
//account
void Funds_Transfer(vector<database> &, CLI *, int *);
void Funds_Add(char *,fstream *);
void Funds_Remove(char *, fstream *);
//support functions
void File_Write(fstream *, database *, int *);
void Class_Load(fstream *, database *);



#endif /* main_h */
