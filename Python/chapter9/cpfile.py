# copy one file content to anther file

import os
import sys


def f2f(f1, f2):
    for line in f1:
        f2.write(line)


def main():
    argv_len = len(sys.argv)
    if argv_len != 3:
        print("the argument is wrong.")
        return
    else:
        f1_name = sys.argv[1]
        f2_name = sys.argv[2]
        if not os.path.exists(f1_name):
            print("the file:%s is not exists." % (f1_name))
            return
        else:
            f1 = open(f1_name, "r")
            f2 = open(f2_name, "wr")
            f2f(f1, f2)
            f1.close()
            f2.close()

if __name__ == "__main__":
    main()
