# use this program to verify the email
import re

re_str = r".+::(\w+@\w+\.\w+)::"
f = open("data.txt", 'r')
for line in f:
    print re.match(re_str, line).groups()[0]

f.close()
