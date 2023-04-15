#!/bin/bash

# Program Number : 15
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : SED - Write a shell script to perform the following (input file “example” will be given).
#                   For a given file, find all the lines containing our search pattern.
#                   List the lines not containing the search string
#                   Matching lines starting with a given pattern and ending in a second pattern
#                   Print a file starting from a certain line until to the end of file.
#                   Search a given pattern in a file and replace with a new pattern and display the file.
#                   Insert a given string at the beginning of each line of the file.
#                   Insert a given string at the end of each line of the file.

while true
do
    echo "
Enter 1 2 .. 7 for respective functions and 8 to exit"
    read inp
    case "$inp" in
    "1") 
    read l
    sed -n /$l/p $1
    ;;
    "2") 
    read l
    sed /$l/d $1
    ;;
    "3") 
    read first
    read second
    sed -n /^$first.*$second$/p $1
    ;;
    "4")
    read l
    sed -n $l,$\p $1
    ;;
    "5")
    read w1
    read w2
    sed s/$w1/$w2/g $1
    ;;
    "6")
    read string
    sed s/^/$string/ $1
    ;;
    "7")
    read string
    sed s/$/$string/ $1
    ;;

    *) exit 0
    esac
done
