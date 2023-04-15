#!/bin/bash

# Program Number : 09
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : A shell script that accepts a file name starting and ending line numbers as arguments and displays all the lines between the given line numbers.​

echo -n "Enter filename: "
read fname
echo -n "Enter start number: "
read l1
echo -n "Enter end number: "
read l2
sed -n $l1,$l2\p $fname | cat > newfile
cat newfile
