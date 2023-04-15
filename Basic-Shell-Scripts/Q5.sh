#!/bin/bash

# Program Number : 05
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Use find to look for a file and echo a suitable message if the file is not found. (You must not store the output of the find to a file)

if [ `find $@ 2>/dev/null` ]
then
	echo "File Found"
else
	echo "File Not Found"
fi
