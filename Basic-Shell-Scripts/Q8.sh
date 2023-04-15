#!/bin/bash

# Program Number : 08
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Take a login name as command – line argument and reports when that person logged in.

echo -n "Enter username: "
read inp
res=`last -w | grep $inp | awk 'FNR == 1 {print $7}'`
usr=`last -w | grep $inp | awk 'FNR == 1 {print $1}'`
if [ $? == 0 ]
then
	echo "User $usr logged in at: $res"
else
	echo "An error occurred..."
fi
