# parse a service file

import os
import sys


def parse_line(line):
    strs = line.split()
    if len(strs) < 3:
        return
    name = strs[0]
    content = strs[1]
    comment = ""
    for i in range(2, len(strs)):
        comment += strs[i]
    print(name, content, comment)


argv_len = len(sys.argv)
if argv_len != 2:
    print("the argument is wrong")
    exit()
else:
    file_name = sys.argv[1]
    if os.path.exists(file_name):
        f = open(file_name)
        for line in f:
            parse_line(line)
        f.close()
