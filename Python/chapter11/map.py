# this program test map function


def my_dic(a, b):
    return (a, b)


#test
l1 = [1, 2, 3]
l2 = ['abc', 'def', 'ghi']


def main():
    print l1
    print l2
    print "this is used by map:", map(my_dic, l1, l2)


if __name__ == "__main__":
    main()
    print "this is used by zip:", zip(l1, l2)
