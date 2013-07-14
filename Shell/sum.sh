#!/bin/bash
#   This shell script is for me practise shell script
#   Write by lfwu at 13-July-2013
#   This program is for digit add
#   Email:zgwulongfei@gmail.com

if [ $# -ne 1 ]
then
    echo "Wrong argument"
    echo "Use program like this:$0 123"
    exit 1
fi

num=$1
divNum=10
sum=0
while [ $num -gt 0 ]
do
    value=`expr $num % $divNum`
    sum=`expr $sum + $value`
    num=`expr $num / $divNum`
done
echo $sum
