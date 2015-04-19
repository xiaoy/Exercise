# this program is used for show file content

import sys
import os


def open_file(filename):
    if not os.path.exists(filename):
        print("the file:%s is not exist" % (filename))
    else:
        return open(filename, "r")


def input_file():
    argv_len = len(sys.argv)
    if argv_len == 2:
        file_name = sys.argv[1]
        f = open_file(file_name)
        print_file(f, 0)
        f.close()
    elif argv_len == 3:
        file_name = sys.argv[1]
        line_count = sys.argv[2]
        f = open_file(file_name)
        print_file(f, line_count)
        f.close()
    else:
        print("the argument is wrong.")


def print_file(f, linecount):
    i = -1
    linecount = int(linecount)
    for line in f:
        i += 1
        if i > linecount:
            break
        else:
            print line,

input_file()
