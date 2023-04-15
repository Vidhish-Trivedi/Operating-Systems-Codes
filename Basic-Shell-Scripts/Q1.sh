#!/bin/bash

# Program Number : 01
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Count the number of block device files in /dev directory. ​

ans=`ls -Rl /dev | grep ^b | wc -l`
echo "Number of block device files in /dev directory is $ans"
