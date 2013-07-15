#!/bin/bash
#This script is for practising shell programing, You can use it anywhere
#Write by lfwu at July-15-2013
#This program is for find the given line range and the str
#Email:zgwulongfei@gmail.com

if [ $# -ne 4 ]
then
    echo "Wrong argument"
    echo "Use script like:$0 1 5 str filename"
fi

awk "/$3/ && NR >= $1 && NR <= $2" $4
