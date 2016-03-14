#!/bin/bash

#  CS202P1Test.sh
#  
#
#  Created by Patrick Kelly on 3/4/16.
#

#vars
FILE=Test
FNAME=Jonny
LNAME=Smithers
MIDDLE=K
SSN=258649137
AREA=557
PHONE=5846958
AMMT=584.32
NEWPASS=POIU00

MAN="$1" || "0"

if [ "$MAN" == "1" ]; then
	echo "Enter file name to use:"
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
else
	ACC_1=AA001
	PAS_1=POIU01
	ACC_2=C123A
	PAS_2=Z52C42
	ACC_3=AA004
	PAS_3=POIU04
fi

VERBOSE="$2" || "0"

#commands
echo
echo
# Verbose check
if [ "$VERBOSE" == "1" ]; then
	# Display account
	./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /I
	echo
	# Change First Name
	./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /F${FNAME}
	echo
	# Change Last Name
	./bankacct /V /D${FILE} /N${ACC_2} /P${PAS_2} /L${LNAME}
	echo
	# Change Middle Initial
	./bankacct /V /D${FILE} /N${ACC_3} /P${PAS_3} /M${MIDDLE}
	echo
	# Change SSN
	./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /S${SSN}
	echo
	# Change Phone Number Area Code
	./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /A${AREA}
	echo
	# Change Phone Number
	./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /H${PHONE}
	echo
	# Transfer money
	./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /N${ACC_2} /P${PAS_2} /T${AMMT}
	echo
	# Change password
	./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /W${NEWPASS}
	echo
	# Print Report file
	./bankacct /V /R${RFILE} /D${FILE}
	echo
else
	# Display account
	./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /I
	echo
	# Change First Name
	./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /F${FNAME}
	echo
	# Change Last Name
	./bankacct /D${FILE} /N${ACC_2} /P${PAS_2} /L${LNAME}
	echo
	# Change Middle Initial
	./bankacct /D${FILE} /N${ACC_3} /P${PAS_3} /M${MIDDLE}
	echo
	# Change SSN
	./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /S${SSN}
	echo
	# Change Phone Number Area Code
	./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /A${AREA}
	echo
	# Change Phone Number
	./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /H${PHONE}
	echo
	# Transfer money
	./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /N${ACC_2} /P${PAS_2} /T${AMMT}
	echo
	# Change password
	./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /W${NEWPASS}
	echo
	# Print Report file
	./bankacct /R${RFILE} /D${FILE}
	echo
fi








