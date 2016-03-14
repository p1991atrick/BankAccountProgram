#!/bin/sh

#  CS202P1Test.sh
#  
#
#  Created by Patrick Kelly on 3/4/16.
#

#vars
FILE=Test
RFILE=
FNAME=Johnny
LNAME=Smith
MIDDLE=X
SSN=453658741
AREA=557
PHONE=6548521
AMMT=653.26
NEWPASS=UIOP00

ACC1=AA001
PAS1=POIU01
ACC2=C123A
PAS2=Z52C42
ACC3=AA004
PAS3=POIU04

#commands

# Display account
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