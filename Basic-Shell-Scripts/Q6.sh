#!/bin/bash

# Program Number : 06
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Give 4 choices to the user 1. ls   2. pwd  3. who 4. exit and execute the command as per the users choice.

while true
do
	echo "Select an option:
1. ls
2. pwd
3. who
4. exit"
	read inp
	if [ $inp == 1 ]
	then
		c=`ls`
		if [ $? == 0 ]
		then
			echo $c
		else
			echo "An error occurred...(ls)"
		fi
	

	elif [ $inp == 2 ]
	then
		c=`pwd`
		if [ $? == 0 ]
		then
			echo $c
		else
			echo "An error occurred...(pwd)"
		fi
	elif [ $inp == 3 ]
	then
		c=`who`
		if [ $? == 0 ]
		then
			echo $c
		else
			echo "An error occurred...(who)"
		fi
	elif [ $inp == 4 ]
	then
		echo "Exiting..."
		exit 0;
	fi
done

