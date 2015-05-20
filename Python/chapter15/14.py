# this program is used to match month

import re

restr1 = r"\b0?[1-9]\b"
restr2 = r"\b1[0-2]\b"


def main():
    input_str = raw_input("input a month:")
    reobj = re.match(restr1, input_str)
    if reobj is None:
        reobj = re.match(restr2, input_str)

    if reobj is None:
        print("you input month:%s is illegal." % (input_str))
    else:
        print("you input month:%s" % (reobj.group()))

if __name__ == "__main__":
    main()
