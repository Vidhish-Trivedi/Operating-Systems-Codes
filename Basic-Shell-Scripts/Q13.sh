#!/bin/bash

# Program Number : 13
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Print a multiplication table.

echo -n "Input a number: "
read inp
for i in {1..10}
do
	r=$(($inp * $i))
	echo "$inp X $i = $r"
done
