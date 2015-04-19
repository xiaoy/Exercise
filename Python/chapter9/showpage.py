# show file content by page

import os
import sys


def show_file(f):
    page_line = 25
    i = 0
    for line in f:
        if i == page_line:
            raw_input("input any char to continue")
            i = 0
        else:
            print line,
        i = i + 1


argv_len = len(sys.argv)
if argv_len != 2:
    print("the argument is wrong.")
else:
    file_name = sys.argv[1]
    if os.path.exists(file_name):
        f = open(file_name,)
        show_file(f)
        f.close()
    else:
        print("the file:%s is not exists" % (file_name))
