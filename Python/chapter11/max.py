# this program is used to get max value in the list
import random


def max2(a, b):
    if a > b:
        return a
    else:
        return b


def min2(a, b):
    if a < b:
        return a
    else:
        return b


def max_list(l):
    count = len(l) - 1
    if count < 0:
        return None

    m = l[0]
    for i in range(1, count):
        m = max2(m, l[i])

    return m


def min_list(l):
    count = len(l) - 1
    if count < 0:
        return None

    m = l[0]
    for i in range(1, count):
        m = min2(m, l[i])

    return m


# test
def main():
    l = [random.randrange(-10, 10) for i in range(random.randrange(5, 10))]
    print l

    # function
    print "max value in list:%d" % (max_list(l))
    print "min value in list:%d" % (min_list(l))


if __name__ == "__main__":
    main()
