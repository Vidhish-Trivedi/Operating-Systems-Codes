#!/bin/bash

# Program Number : 11
# Name : Vidhish Trivedi
# Register Number : IMT2021055
# Date : 13/1/2022
# Description : A script to check how much space is used by each directory of a given file system.

filesys=`df | grep $@ | awk '{print $NF}'`
sudo du $filesys
