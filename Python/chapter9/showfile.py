# this program is used for show file content

import sys
import os

if len(sys.argv) != 2:
    print("the argument is wrong")
else:
    filename = sys.argv[1]
    if not os.path.exists(filename):
        print("the file:%s is not exist" % (filename))
    else:
        f = open(filename, "r")
        for line in f:
            if line[0] == "#":
                continue
            print line,
