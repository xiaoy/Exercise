# this program is used to find if string include these strings
#["bat", "bit", "but", "hat", "hit", "hut"]

import re

regstr = r".*(bat|bit|but|hat|hit|hut)"


def main():
    input_str = raw_input("input string you want to check:")
    reg_obj = re.match(regstr, input_str)

    if reg_obj is not None:
        print reg_obj.group()


if __name__ == "__main__":
    main()
