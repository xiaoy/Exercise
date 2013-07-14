#!/bin/bash
#   This shell script is for me practise shell script
#   Write by lfwu at 13-July-2013
#   This program is use for print algorithm
#   Email:zgwulongfei@gmail.com

if [ $# -lt 3 ] 
then
    echo "Use this script by:$0 x [+,-,x,/] y"
    exit 1
fi

case $2 in
    "+") echo "$1 + $3 = `expr $1 + $3`";;
    "-") echo "$1 - $3 = `expr $1 - $3`";;
    "x") echo "$1 x $3 = `expr $1 \* $3`";;
    "/") echo "$1 / $3 = `expr $1 / $3`";;
    *)  echo "Wrong symbol";;
esac
