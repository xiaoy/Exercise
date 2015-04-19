# show file lines

import sys
import os

if len(sys.argv) != 2:
    print("the argument is wrong")
else:
    filename = sys.argv[1]
    if not os.path.exists(filename):
        print("the file:%s is not exists." % (filename))
    else:
        f = open(filename, "r")
        print("the file:%s has %d lines" % (filename, len(f.readlines())))
        f.close()
