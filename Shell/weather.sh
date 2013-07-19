#!/bin/bash
#This script is for practising shell programing, You can use it anywhere
#Write by lfwu at July-19-2013
#This program is for to get temperature from yahoo
#Email:zgwulongfei@gmail.com

# load html info from yahoo website
echo "Get data from http://weather.yahoo.com/"
curl -# "http://weather.yahoo.com/" >/tmp/html.$$
# get the weather info lines
sed -n '/day-temp-current/p' /tmp/html.$$ >/tmp/line.$$
# apart the info to lines
sed 's/day-temp-current temp-c/\n&/g' /tmp/line.$$ >/tmp/lines.$$
# filter the current-temp info
sed -n '/day-temp-current temp-c  hide/p' /tmp/lines.$$ >/tmp/temp.$$
# delete the info from & to the end
sed 's/&.*//g' /tmp/temp.$$ >/tmp/info.$$
# delete the info from begin to the number
ret=$(sed 's/.*[^0-9]//g' /tmp/info.$$)
echo "current temperature is: $ret c"
#clear the temp files
rm -f /tmp/html.* /tmp/line.* /tmp/lines.* \
    /tmp/temp.* /tmp/info.*
