#!/bin/bash
#   This shell script is for me practise shell script
#   Write by lfwu at 14-July-2013
#   This program is use for print reverse number
#   Email:zgwulongfei@gmail.com

if [ $# -ne 1 ]
then
    echo "The argument is count is wrong"
    echo "Use this program like:$0 x"
    exit 1
fi

num=$1
reverse=0
index=10
while [ $num -gt 0 ]
do
    value=`expr $num % 10`
    reverse=$(($index*$reverse+$value))
    num=$(($num/10))
done

echo $reverse
