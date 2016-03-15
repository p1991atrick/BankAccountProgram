#!/bin/bash

#  CS202P1Test.sh
#  
#
#  Created by Patrick Kelly on 3/4/16.
#
#  This tool requires 2 cli args, the first and second ones SHOULD be '0'.
#	If you understand what the arg's do you are free to use other options.
#


### Var's ###
ACC_1=AA001
PAS_1=POIU01
ACC_2=C123A
PAS_2=Z52C42
ACC_3=AA004
PAS_3=POIU04
#############

### DO NOT TOUCH!! ###
###################
MAN="$1" || "0" ### DO NOT TOUCH!! ###
VERBOSE="$2"||"0" ### DO NOT TOUCH!! ###
PERSONAL="$3"||"0" ### DO NOT TOUCH!! ###
###################
### DO NOT TOUCH!! ###

## Code ##

if [ "$MAN" == "0" ]; then
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
	FILE=Test
	FNAME=Jonny
	LNAME=Smithers
	MIDDLE=K
	SSN=258649137
	AREA=557
	PHONE=5846958
	AMMT=584.32
	NEWPASS=POIU00
fi


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
	./bankacct /V /D${FILE} /N${ACC_2} /P${PAS_2} /S${SSN}
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
	if [ "$PERSONAL" == "1" ]; then
		# Create Account
		./bankacct /V /C /F${FNAME} /L${LNAME} /M${MIDDLE} /S${SSN} /A${AREA} /H${PHONE} /NAA010 /PPOIU10 /T78594.39 /D${FILE}
		echo
		# Display Database file
		cat $FILE
		echo
		echo "----"
		read -p "Press Enter To Continue"
		# Remove Account From Database
		./bankacct /V /X /NAA010 /PPOIU10 /D${FILE}
	fi
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

echo "End of File."
echo
## END ##

###########  ONLY CHANGE STUFF HERE IF YOU KNOW WHAT IT DOES ############
#if [ "$MAN" == "999" ]; then
#	echo "Where is the database file?"
#	read FILE
#	while [ACCOUNT=`cat $FILE`]
#	do
### CODE GOES HERE ##
#	done
#
#fi


























