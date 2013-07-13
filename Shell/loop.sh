#!/bin/bash
#   This shell script is for me practise shell script
#   Write by lfwu at 13-July-2013
#   This program is for find the biggest num in three nos
#   Email:zgwulongfei@gmail.com

if [ $# -lt 1 ] 
then
    echo "Wrong argument, use: $0 x"
    exit
fi

max=$1
while [ $max -gt 0 ]
do
    max=$(($max-1))
    echo $max
done
