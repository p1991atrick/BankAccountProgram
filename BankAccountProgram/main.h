//
//  main.h
//  BankAccountProgram
//
//  Created by Gordon Freeman on 3/5/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#ifndef main_h
#define main_h


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
void CLI_Args(int, char *argv[], char *, char *, Command_line_Record *);
void CLI_Help();
void Record_Sort(Command_line_Record *, fstream *, char *, char *);
void CLI_Sort(Command_line_Record *, database *, bool *);
//file IO
void Open_File(char *, fstream *);
//management
void Add_Account(Command_line_Record *, vector<database> &, int *, int *);
void Display_Database(database *);
int Delete_Account(vector<database> &, Command_line_Record *, int *);
void Print_Report(char *, vector<database> &, int *);
//account
void Funds_Transfer(vector<database> &, Command_line_Record *);
void Funds_Remove(char *, fstream *);

#endif /* main_h */
