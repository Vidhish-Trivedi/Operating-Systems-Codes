#!/bin/bash

# Program Number : 02
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Check the number of command line arguments
# 				and echoes an error message if there are not exactly three arguments
# 				or echoes the arguments themselves if there are three​.

if [ $# -eq 3 ]
then
	echo First: $1 Second: $2 Third: $3
else
	echo 3 arguments were not given.
fi
