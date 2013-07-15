#!/bin/bash
#This script is for practising shell programing, You can use it anywhere
#Write by lfwu at July-15-2013
#This program is for check there is a char in a string
#Email:zgwulongfei@gmail.com

if [ $# -ne 1 ]
then
    echo "Wrong argument input"
    echo "Use script by $0 \"string\""
    exit 1
fi

echo $1 >/tmp/file.$$
grep "*" /tmp/file.$$ >/tmp/file0.$$

if [ $? -eq 0 ]
then
    echo "Find the * in $1"
else
    echo "Can't find the * in $1"
fi

rm /tmp/file.$$
rm /tmp/file0.$$
exit 1
