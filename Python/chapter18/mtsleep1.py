# this program used to test sleep function

import thread
from time import ctime, sleep


def loop(index, sleepTime):
    print "start loop %s at:%s" % (index, ctime())
    sleep(sleepTime)
    print "end loop %s at:%s" % (index, ctime())


def main():
    print "starting at:", ctime()
    thread.start_new_thread(loop, (0, 2))
    thread.start_new_thread(loop, (1, 4))
    sleep(6)
    print "all done at:", ctime()


if __name__ == "__main__":
    main()
