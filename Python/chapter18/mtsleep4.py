# this program is used to test threading

import threading
from time import ctime, sleep


loops = [4, 2]


class ThreadFunc(object):
    def __init__(self, func, args, name=""):
        self.func = func
        self.args = args
        self.name = name

    def __call__(self):
        apply(self.func, self.args)


def loop(nloop, nsec):
    print "start loop", nloop, "at:", ctime()
    sleep(nsec)
    print "end loop", nloop, "at:", ctime()


def main():
    print "start at:", ctime()
    threads = []

    nloops = range(len(loops))
    for i in nloops:
        t = threading.Thread(target=ThreadFunc(loop,
                                               args=(i, loops[i])))
        threads.append(t)

    for i in nloops:
        threads[i].start()

    for i in nloops:
        threads[i].join()

    print "end at:", ctime()


if __name__ == "__main__":
    main()
