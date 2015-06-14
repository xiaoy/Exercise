# this program used to test lock function

import thread
from time import ctime, sleep


loops = [4, 2]


def loop(index, sleepTime, lock):
    print "start loop %s at:%s" % (index, ctime())
    sleep(sleepTime)
    print "end loop %s at:%s" % (index, ctime())
    lock.release()


def main():
    print "start at:", ctime()
    nloops = range(len(loops))

    locks = []
    for i in nloops:
        lock = thread.allocate_lock()
        lock.acquire()
        locks.append(lock)

    for i in nloops:
        thread.start_new_thread(loop, (i, loops[i], locks[i]))

    for i in nloops:
        while locks[i].locked():
            pass

    print "end at:", ctime()

if __name__ == "__main__":
    main()
