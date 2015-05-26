# use this program to verify the month
import re

re_str = r".+(Jan|Feb|Mar|Jan|Jul|Apr|Sep|Oct|Nov)"
f = open("data.txt", 'r')
for line in f:
    print re.match(re_str, line).groups()[0]

f.close()
