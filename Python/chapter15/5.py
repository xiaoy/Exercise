# this used to math string name

import re


regstr = r"([1-9])+( [a-zA-Z])+"


def main():
    input_str = raw_input("input a street address:")
    regobj = re.match(regstr, input_str)

    if regobj is None:
        print("the street name is illegal")
    else:
        print("the street name is legal")


if __name__ == "__main__":
    main()
