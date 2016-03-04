#!/bin/sh

#  CS202P1Test.sh
#  
#
#  Created by Patrick Kelly on 3/4/16.
#

#vars
FILE=
RFILE=
FNAME=
LNAME=
MIDDLE=
SSN=
AREA=
PHONE=
AMMT=
NEWPASS=

ACC1=
PAS1=
ACC2=
PAS2=
ACC3=
PAS3=

#commands

#  Display account
./bankacct /D$(FILE) /N$(ACC1) /P$(PAS1) /I

# Change First name
./bankacct /D$(FILE) /N$(ACC1) /P$(PAS1) /F$(FNAME)

# Change Last name
./bankacct /D$(FILE) /N$(ACC2) /P$(PAS2) /L$(LNAME)

# Change Middle initial
./bankacct /D$(FILE) /N$(ACC3) /P$(PAS3 ) /M$(MIDDLE)

# Change ssn
./bankacct /D$(FILE) /N$(ACC1) /P$(PAS1) /S$(SSN)

# Change phonenumber area code
./bankacct /D$(FILE) /N$(ACC1) /P$(PAS1) /A$(AREA)

# Change phonenumber area code
./bankacct /D$(FILE) /N$(ACC1) /P$(PAS1) /H$(PHONE)

# Transfer money
./bankacct /D$(FILE) /N$(ACC1) /P$(PAS1) /N$(ACC2) /P$(PAS2) /T$(AMMT)

# Change password
./bankacct /D$(FILE) /N$(ACC1) /P$(PAS1) /W$(NEWPASS)

# Print Report file
./bankacct /R$(RFILE) /D$(FILE)