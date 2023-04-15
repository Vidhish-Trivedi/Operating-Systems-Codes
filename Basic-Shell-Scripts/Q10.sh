#!/bin/bash

# Program Number : 10
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : A script to backup a given directory to a given file name  in your home directory. ​

dir_to_backup=$1
backup_name=$2
if [[ -d $1 ]]
then
    tar -P -cvf $backup_name.tar $dir_to_backup
    mv $backup_name ~/
else
    echo "Directory to backup doesn't exist"
fi