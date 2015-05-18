# this program is used to math type

import re


class Foo(object):
    pass


restr = r"'(.)+'"


def test(var):
    type_str = type(var)
    print(type_str)
    reobj = re.search(restr, str(type_str))

    if reobj is None:
        print("you input type is not exist")
    else:
        print("you input type is:%s " % (reobj.group()))


def main():
    # int
    test(1)

    # float
    test(1.0)

    # class
    test(Foo())

    # function
    func = lambda x, y: x + y
    test(func)


if __name__ == "__main__":
    main()
