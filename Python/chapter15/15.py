# this program is used to match credit card number

import re

# 16 bit
restr_16 = r"([0-9]{4}-){3}[0-9]{4}"
restr_15 = r"[0-9]{4}-[0-9]{6}-[0-9]{4}"


def test(restr, num):
    reobj = re.match(restr, num)
    if reobj is None:
        print("your number:%s is illegal" % (num))
    else:
        print("your number:%s is legal" % (num))


def main():
    num = '1234-1234-1234-1234'
    test(restr_16, num)

    num = '1234-1234-12341234'
    test(restr_16, num)

    num = '134-1234-12341234'
    test(restr_16, num)

    num = 'a134-1234-12341234'
    test(restr_16, num)

    num = '1234-123456-12345'
    test(restr_15, num)


if __name__ == "__main__":
    main()
