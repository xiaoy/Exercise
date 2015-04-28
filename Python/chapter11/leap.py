# this program is used to just the leap year


def main():
    l = [x for x in range(2000, 2030)]

    def isleap(x):
        if x % 100 == 0 and x % 400 != 0:
            return False
        elif x % 4 == 0:
            return True
        else:
            return False

    print "the year list:"
    print l
    print "the leap year list:"
    print filter(isleap, l)


if __name__ == "__main__":
    main()
