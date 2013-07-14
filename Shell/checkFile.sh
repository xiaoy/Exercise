#!/bin/bash
#   This shell script is for me practise shell script
#   Write by lfwu at 14-July-2013
#   This program is for check the file is exist
#   Email:zgwulongfei@gmail.com

if [ $# -ne 1 ]
then
    echo "The argument is wrong"
    echo "Use script like:$0 filename"
    exit 1
fi

if test -f $1
then
    echo "the $1 is exist"
else
    echo "the $1 is not exist"
fi
    exit 1
