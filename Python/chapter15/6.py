# to check the domain name

import re

regstr = r"www\.(\w)+\.[com|edu|cn|net]+"


def main():
    input_str = raw_input("input a domain name:")
    regobj = re.match(regstr, input_str)
    if regobj is None:
        print("the domain name:%s is illegal" % (input_str))
    else:
        print("the domain name:%s is legal" % (input_str))


if __name__ == "__main__":
    main()
