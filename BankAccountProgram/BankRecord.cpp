//
//  BankRecord.cpp
//  BankAccountProgram
//
//  Created by Gordon Freeman on 2/2/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#include "BankRecord.hpp"
#include <ostream>

database::database()
{
    strncpy(LName, "none", 5);
    strncpy(FName, "none", 5);
    
}