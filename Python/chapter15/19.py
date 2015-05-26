# use this program to verify the time
import re

re_str = r"(.+\d+)::"
f = open("data.txt", 'r')
for line in f:
    print re.match(re_str, line).groups()[0]

f.close()
