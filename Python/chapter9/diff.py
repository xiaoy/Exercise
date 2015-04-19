# duff two file content

import os
import sys


def get_col_num(str1, str2):
    str1_len, str2_len = len(str1), len(str2)
    str_len = 0
    if str1_len < str2_len:
        str_len = str1_len
        return str_len
    elif str1_len > str2_len:
        str_len = str2_len
        return str_len
    else:
        str_len = str1_len

    for i in range(str_len):
        if str1[i] != str2[i]:
            return i

    return 0


def diff_file(f1, f2):
    f1_content = []
    for line in f1:
        f1_content.append(line)

    line_index = 0
    for line in f2:
        line1 = f1_content[line_index]
        col = get_col_num(line, line1)
        if col != 0:
            print("the file:%s %s is not same at line:%d, col:%d"
                  % (f1.name, f2.name, line_index, col))
            break
        line_index += 1


argv_len = len(sys.argv)
if argv_len != 3:
    print("the argument is wrong")
else:
    filename1 = sys.argv[1]
    filename2 = sys.argv[2]
    if not os.path.exists(filename1):
        print("the file:%s is not exists" % (filename1))
        exit()

    if not os.path.exists(filename2):
        print("the file:%s is not exists" % (filename2))
        exit()

    f1 = open(filename1, "r")
    f2 = open(filename2, "r")

    diff_file(f1, f2)

    f1.close()
    f2.close()
