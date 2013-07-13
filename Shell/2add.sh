#!/bin/bash
#   This shell script is for me practise shell script
#   Write by lfwu at 13-July-2013
#   This program is for add two numbers
#   Email:zgwulongfei@gmail.com

if [ $# -ne 2 ]
then
    echo "Wrong argument use: $0 x y"
else
    echo "x + y = `expr $1 + $2`"
fi
exit 1

