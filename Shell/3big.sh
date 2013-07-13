#!/bin/bash
#   This shell script is for me practise shell script
#   Write by lfwu at 13-July-2013
#   This program is for find the biggest num in three nos
#   Email:zgwulongfei@gmail.com

if [ $# -ne 3 ]
then
    echo "the argument is wrong, use:$0 x y z"
    exit 1
fi
if [ $1 -le $2 ]
then
    num1=$2
else
    num1=$1
fi

if [ $3 -le $num1 ]
then
    num2=$num1
else
    num2=$3
fi

echo "The greater number is: $num2"
exit 1
