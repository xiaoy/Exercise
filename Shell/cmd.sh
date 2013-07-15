#!/bin/bash
#This script is for practising shell programing, You can use it anywhere
#Write by lfwu at July-15-2013
#This program is for call shell command
#Email:zgwulongfei@gmail.com

if [ $# -ne 1 ]
then
    echo "Wrong argument"
    echo "Use $0 -c to clear the screen"
    echo "Use $0 -d show list of files in current working directory"
    echo "Use $0 -m start mc"
    echo "Use $0 -e start editor"
    exit 1
fi

case $1 in
    -c)cmd="clear";;
    -d)cmd="ls";;
    -m)cmd="mc";;
    -e)cmd="editor";;
     *)echo "wrong argument";;
esac
$cmd
exit 1
