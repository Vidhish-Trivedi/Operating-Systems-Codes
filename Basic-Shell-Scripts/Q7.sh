#!/bin/bash

# Program Number : 07
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : An interactive file-handling shell program that offers the user choice of copying, removing, renaming.

while true
do
	echo "Select option:
1. Copy a file.
2. Remove a file.
3. Rename a file.
4. Exit."
	read inp
	if [ $inp == 1 ]
	then
		echo -n "Input filename to copy: "
		read f1
		echo -n "Input destination path: "
		read f2
		c=`cp $f1 $f2`
		echo "Copying $f1 to $f2..."
		if [ $? == 0 ]
		then
			echo "Done..."
		else
			echo "An error occurred while copying..."
		fi
	
	elif [ $inp == 2 ]
	then
		echo -n "Input filename to remove: "
		read f1
		c=`rm $f1`
		echo "Removing $f1..."
		if [ $? == 0 ]
		then
			echo "Done..."
		else
			echo "An error occurred while removing..."
		fi
	
	elif [ $inp == 3 ]
	then
		echo -n "Input current name: "
		read f1
		echo -n "Input new name: "
		read f2
		echo "Renaming..."
		c=`mv $f1 $f2`
		if [ $? == 0 ]
		then
			echo "Done..."
		else
			echo "An error occurred while renaming..."
		fi

	elif [ $inp == 4 ]
	then
		echo "Exiting..."
		exit 0
	
	else
		echo "Invalid choice..."
	fi
done
