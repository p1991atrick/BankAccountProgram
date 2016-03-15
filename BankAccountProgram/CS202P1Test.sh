#!/bin/bash

#  CS202P1Test.sh
#  
#
#  Created by Patrick Kelly on 3/4/16.
#
#  This tool uses CLI arguments.
#	If you understand what the arg's do you are free to use them.
#


### Account Var's ###
ACC_1=AA001
PAS_1=POIU01
ACC_2=C123A
PAS_2=Z52C42
ACC_3=AA004
PAS_3=POIU04
#####################

### DO NOT TOUCH!! ###
###################
if [ "$1" = "1" ]; then ### DO NOT TOUCH!! ###
	MAN="$1"
else
	MAN="0"
fi
if [ "$2" = "1" ];then ### DO NOT TOUCH!! ###
	VERBOSE="$2"
else
	VERBOSE="0"
fi
if [ "$3" = "1" \];then ### DO NOT TOUCH!! ###
	PERSONAL="$3"
else
	PERSONAL="0"
fi
SYS=`uname` ### DO NOT TOUCH!! ###
###################
### DO NOT TOUCH!! ###

## Code ##

if [ "$MAN" = "0" ]; then
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
	FILE=Test.db
	FNAME=Jonny
	LNAME=Smithers
	MIDDLE=K
	SSN=258649137
	AREA=557
	PHONE=5846958
	AMMT=584.32
	NEWPASS=POIU00
fi


# Commands
echo
if [ "$SYS" = "Linux" ]; then ## For Linux
	echo "Running for Linux... "
	echo
	sleep 1
	# Verbose check
	if [ "$VERBOSE" == "1" ]; then
		# Display account
		./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /I
		echo
		sleep 1
		# Change First Name
		./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /F${FNAME}
		echo
		sleep 1
		# Change Last Name
		./bankacct /V /D${FILE} /N${ACC_2} /P${PAS_2} /L${LNAME}
		echo
		sleep 1
		# Change Middle Initial
		./bankacct /V /D${FILE} /N${ACC_3} /P${PAS_3} /M${MIDDLE}
		echo
		sleep 1
		# Change SSN
		./bankacct /V /D${FILE} /N${ACC_2} /P${PAS_2} /S${SSN}
		echo
		sleep 1
		# Change Phone Number Area Code
		./bankacct /V /D${FILE} /N${ACC_3} /P${PAS_3} /A${AREA}
		echo
		sleep 1
		# Change Phone Number
		./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /H${PHONE}
		echo
		sleep 1
		# Transfer money
		./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /N${ACC_2} /P${PAS_2} /T${AMMT}
		echo
		sleep 1
		# Change password
		./bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /W${NEWPASS}
		echo
		sleep 1
		# Print Report file
		./bankacct /V /R${RFILE} /D${FILE}
		echo
		sleep 1
		if [ "$PERSONAL" = "1" ]; then
			# Create Account
			./bankacct /V /C /F${FNAME} /L${LNAME} /M${MIDDLE} /S${SSN} /A${AREA} /H${PHONE} /NAA010 /PPOIU10 /T78594.39 /D${FILE}
			echo
			sleep 1
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
		echo "--------Displayed Account--------"
		sleep 1
		# Change First Name
		./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /F${FNAME}
		echo "--------Changed First Name--------"
		sleep 1
		# Change Last Name
		./bankacct /D${FILE} /N${ACC_2} /P${PAS_2} /L${LNAME}
		echo "--------Changed Last Name--------"
		sleep 1
		# Change Middle Initial
		./bankacct /D${FILE} /N${ACC_3} /P${PAS_3} /M${MIDDLE}
		echo "--------Changed Middle Initial--------"
		sleep 1
		# Change SSN
		./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /S${SSN}
		echo "--------Changed SSN--------"
		sleep 1
		# Change Phone Number Area Code
		./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /A${AREA}
		echo "--------Changed Area Code--------"
		sleep 1
		# Change Phone Number
		./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /H${PHONE}
		echo "--------Changed Phone Number--------"
		sleep 1
		# Transfer money
		./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /N${ACC_2} /P${PAS_2} /T${AMMT}
		echo "--------Transfered Funds--------"
		sleep 1
		# Change password
		./bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /W${NEWPASS}
		echo "--------Changed Password--------"
		sleep 1
		# Print Report file
		./bankacct /R${RFILE} /D${FILE}
		echo "--------Printed Report File--------"
		sleep 1
			if [ "$PERSONAL" == "1" ]; then
			# Create Account
			./bankacct /C /F${FNAME} /L${LNAME} /M${MIDDLE} /S${SSN} /A${AREA} /H${PHONE} /NAA010 /PPOIU10 /T78594.39 /D${FILE}
			echo "--------Created Account--------"
			sleep 1
			# Display Database file
			cat $FILE
			echo
			echo "----"
			read -p "Press Enter To Continue"
			# Remove Account From Database
			./bankacct /X /NAA010 /PPOIU10 /D${FILE}
			echo "--------Removed Account--------"
			sleep 1
			fi
	fi

	echo "End of Test File."
	echo
	## END ##

elif [ "$SYS" == "Darwin" ]; then ## For Mac
	echo "Running for Mac... "
	echo
	sleep 1
	if [ "$VERBOSE" = "1" ]; then
		# Display account
		bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /I
		echo
		sleep 1
		# Change First Name
		bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /F${FNAME}
		echo
		sleep 1
		# Change Last Name
		bankacct /V /D${FILE} /N${ACC_2} /P${PAS_2} /L${LNAME}
		echo
		sleep 1
		# Change Middle Initial
		bankacct /V /D${FILE} /N${ACC_3} /P${PAS_3} /M${MIDDLE}
		echo
		sleep 1
		# Change SSN
		bankacct /V /D${FILE} /N${ACC_2} /P${PAS_2} /S${SSN}
		echo
		sleep 1
		# Change Phone Number Area Code
		bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /A${AREA}
		echo
		sleep 1
		# Change Phone Number
		bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /H${PHONE}
		echo
		sleep 1
		# Transfer money
		bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /N${ACC_2} /P${PAS_2} /T${AMMT}
		echo
		sleep 1
		# Change password
		bankacct /V /D${FILE} /N${ACC_1} /P${PAS_1} /W${NEWPASS}
		echo
		sleep 1
		# Print Report file
		bankacct /V /R${RFILE} /D${FILE}
		echo
		sleep 1
		if [ "$PERSONAL" = "1" ]; then
			# Create Account
			bankacct /V /C /F${FNAME} /L${LNAME} /M${MIDDLE} /S${SSN} /A${AREA} /H${PHONE} /NAA010 /PPOIU10 /T78594.39 /D${FILE}
			echo
			sleep 1
			# Display Database file
			cat $FILE
			echo
			echo "----"
			read -p "Press Enter To Continue"
			# Remove Account From Database
			bankacct /V /X /NAA010 /PPOIU10 /D${FILE}
		fi
	else
		# Display account
		bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /I
		echo "--------Displayed Account--------"
		sleep 1
		# Change First Name
		bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /F${FNAME}
		echo "--------Changed First Name--------"
		sleep 1
		# Change Last Name
		bankacct /D${FILE} /N${ACC_2} /P${PAS_2} /L${LNAME}
		echo "--------Changed Last Name--------"
		sleep 1
		# Change Middle Initial
		bankacct /D${FILE} /N${ACC_3} /P${PAS_3} /M${MIDDLE}
		echo "--------Changed Middle Initial--------"
		sleep 1
		# Change SSN
		bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /S${SSN}
		echo "--------Changed SSN--------"
		sleep 1
		# Change Phone Number Area Code
		bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /A${AREA}
		echo "--------Changed Area Code--------"
		sleep 1
		# Change Phone Number
		bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /H${PHONE}
		echo "--------Changed Phone Number--------"
		sleep 1
		# Transfer money
		bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /N${ACC_2} /P${PAS_2} /T${AMMT}
		echo "--------Transfered Funds--------"
		sleep 1
		# Change password
		bankacct /D${FILE} /N${ACC_1} /P${PAS_1} /W${NEWPASS}
		echo "--------Changed Password--------"
		sleep 1
		# Print Report file
		bankacct /R${RFILE} /D${FILE}
		echo "--------Printed Report File--------"
		sleep 1
		if [ "$PERSONAL" = "1" ]; then
			# Create Account
			bankacct /C /F${FNAME} /L${LNAME} /M${MIDDLE} /S${SSN} /A${AREA} /H${PHONE} /NAA010 /PPOIU10 /T78594.39 /D${FILE}
			echo "--------Created Account--------"
			sleep 1
			# Display Database file
			cat $FILE
			echo
			echo "----"
			read -p "Press Enter To Continue"
			# Remove Account From Database
			bankacct /X /NAA010 /PPOIU10 /D${FILE}
			echo "--------Removed Account--------"
			sleep 1
		fi
	fi

	echo "End of Test File."
	echo
	## END ##
fi


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


























