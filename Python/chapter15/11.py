# this program is used to math email address

import re

restr = r"(\w)+@(\w)+\.[com|cn|net|edu|org]"


def main():
    input_str = raw_input("input email address:")
    reojb = re.match(restr, input_str)

    if reojb is None:
        print("you input email:%s is illegal" % (input_str))
    else:
        print("you input email:%s is legal" % (input_str))


if __name__ == "__main__":
    main()
