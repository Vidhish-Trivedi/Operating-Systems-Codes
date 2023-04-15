#!/bin/bash

# Program Number : 03
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Accept a variable number of command line arguments
#				and creates a new file associated with each command line argument and echo a message that notifies the user as each file is created. ​

cnt=1
args=("$@")
while [ $cnt -le $# ]
do
	touch file${args[`expr $cnt - 1`]}.txt
	echo file${args[`expr $cnt - 1`]}.txt created.
	cnt=`expr $cnt + 1`
done
echo done...

