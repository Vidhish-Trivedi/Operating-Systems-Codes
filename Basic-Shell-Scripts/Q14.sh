#!/bin/bash

# Program Number : 14
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Print “Good Morning/Afternoon/Evening based on the current system time.

hr=`date "+%H"`
if [ $hr -ge 0 -a $hr -lt 12 ]
then
    echo "Good Morning"
elif [ $hr -ge 12 -a $hr -lt 16 ]
then
    echo "Good Afternoon"
else
    echo "Good Evening"
fi
