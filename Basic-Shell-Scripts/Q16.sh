#!/bin/bash

# Program Number : 16
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : AWK – Write a Shell script to (The input file “employee.txt” will be given)
#                   Display a given file.
#                   Print the lines which match with a given pattern.
#                   Print only a specific field in the file.
#                   Format a given file with Name, Designation, Department and Salary headings and at the end of a file print Report Generated.
#                   Find the employees, who has id > 200
#                   Find the list of employees in a Technology Department.
#                   Print the number of employees in Technology Department. ​

fn=$1
while true
do
    echo "Enter 1 2 .. 7 for respective functions and 8 to exit"
    read inp
    case "$inp" in
    
    "1") 
    awk '{print $0}' $fn
    ;;
    "2") 
    read l
    awk /$l/ $fn
    ;;
    "3") 
    read col
    awk -v col1=$col '{print $col1}' $fn
    ;;
    "4")
    awk 'BEGIN {print "Name\tDesignation\tDepartment\tSalary";} {print $2,"\t",$3,"\t",$4,"\t",$NF;} END {print "Report Generated\n--------------";}' $fn
    ;;
    "5")
    awk '$1 >200' $fn
    ;;
    "6")
    awk '$4 ~/Technology/' $fn
    ;;
    "7")
    awk 'BEGIN { cnt=0;} $4 ~ /Technology/ { cnt++; } END { print "Number of employees in Technology Dept =",cnt;}' $fn
    ;;
    *) exit 0
    
    esac
done
