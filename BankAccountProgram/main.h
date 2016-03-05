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

#endif /* main_h */
