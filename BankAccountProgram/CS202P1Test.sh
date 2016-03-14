#!/bin/sh

#  CS202P1Test.sh
#  
#
#  Created by Patrick Kelly on 3/4/16.
#

#vars
echo "Enter file name:"
read FILE
echo "Enter First name to use:"
read FNAME
echo "Enter Last name to use:"
read LNAME
echo "Enter Middle Initial to use:"
read MIDDLE
echo "Enter SSN to use:"
read SSN
echo "Enter Phone Number Area Code to use:"
read AREA
echo "Enter Phone Number to use:"
read PHONE
echo "Enter Balance to use:"
read AMMT
echo "Enter New Password to use:"
read NEWPASS


ACC_1=AA001
PAS_1=POIU01
ACC_2=C123A
PAS_2=Z52C42
ACC_3=AA004
PAS_3=POIU04

#commands

# Display account
./bankacct /D$FILE /N$ACC_1 /P$PAS_1 /I

# Change First name
./bankacct /D$FILE /N$ACC_1 /P$PAS_1 /F$FNAME

# Change Last name
./bankacct /D$FILE /N$ACC_2 /P$PAS_2 /L$LNAME

# Change Middle initial
./bankacct /D$FILE /N$ACC_3 /P$PAS_3  /M$MIDDLE

# Change ssn
./bankacct /D$FILE /N$ACC_1 /P$PAS_1 /S$SSN

# Change phonenumber area code
./bankacct /D$FILE /N$ACC_1 /P$PAS_1 /A$AREA

# Change phonenumber area code
./bankacct /D$FILE /N$ACC_1 /P$PAS_1 /H$PHONE

# Transfer money
./bankacct /D$FILE /N$ACC_1 /P$PAS_1 /N$ACC_2 /P$PAS_2 /T$AMMT

# Change password
./bankacct /D$FILE /N$ACC_1 /P$PAS_1 /W$NEWPASS

# Print Report file
./bankacct /R$RFILE /D$FILE