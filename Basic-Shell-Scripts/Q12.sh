#!/bin/bash

# Program Number : 12
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Write a script in /root/myscript.sh according to the following criteria:
#                   If you search for the IIT the output is NIT
#                   If you search for NIT the output is IIT
#                   If you search any other keyword or not give any input, the output is STDERR should be displayed​

read input
case "$input" in
    "IIT") echo "NIT"
    ;;
    "NIT") echo "IIT"
    ;;
    *) echo "STDERR"
esac
