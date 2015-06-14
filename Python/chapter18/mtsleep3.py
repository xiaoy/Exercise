# this program used to test lock function

import threading
from time import ctime, sleep


loops = [4, 2]


def loop(index, sleepTime):
    print "start loop %s at:%s" % (index, ctime())
    sleep(sleepTime)
    print "end loop %s at:%s" % (index, ctime())


def main():
    print "start at:", ctime()
    nloops = range(len(loops))

    threads = []

    for i in nloops:
        t = threading.Thread(target=loop,
                             args=(i, loops[i]))
        threads.append(t)

    for i in nloops:
        threads[i].start()

    for i in nloops:
        threads[i].join()

    print "end at:", ctime()

if __name__ == "__main__":
    main()
