# this program used to test sleep function

from time import ctime, sleep


def loop(index, sleepTime):
    print "start loop %s at:%s" % (index, ctime())
    sleep(sleepTime)
    print "end loop %s at:%s" % (index, ctime())


def main():
    print "starting at:", ctime()
    loop(0, 2)
    loop(1, 4)
    print "all done at:", ctime()


if __name__ == "__main__":
    main()
