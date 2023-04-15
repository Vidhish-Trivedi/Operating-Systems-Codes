#!/bin/bash

# Program Number : 04
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : Move all of the files you delete into the .recyclebin directory, your wastebasket.
#               This is a useful tool which will allow restoration of files after they have been removed​

dir=$(pwd)
echo moving $dir/$1...
mv $dir/$1 ~/.recyclebin
echo "done..."
