# this program used to match a group word split with common and space


import re


def main():
    regstr = r"(\w)+(, )(\w)+"
    input_str = raw_input("input world to match:")
    reobj = re.match(regstr, input_str)

    if reobj is not None:
        print reobj.group()


if __name__ == "__main__":
    main()
