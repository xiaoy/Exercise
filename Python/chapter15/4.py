# check the python variable is right

import re

regstr = r"[A-Za-z|_]([\w|_])?"


def main():
    input_str = raw_input("input a python variable to check:")
    regobj = re.match(regstr, input_str)

    if regobj is None:
        print("Illegal variable")
    else:
        print("legal variable")


if __name__ == "__main__":
    main()
