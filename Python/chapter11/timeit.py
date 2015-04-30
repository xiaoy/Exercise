# this program is used to test a function used time
import time


def timeit(func, x):
    time_now = time.time()
    result = func(x)
    detTime = time.time() - time_now
    print("%s run used time %d" % (func.__name__, detTime))

    return result


def is_primer(x):
    if x % 2 == 0:
        return False
    x = x / 2
    for i in xrange(3, x):
        if x % i == 0:
            return False

    return True


def get_primer_count(x):
    count = 0
    for i in range(x):
        if is_primer(i):
            count += 1

    return count


def test():
    x = 100101011
    ret = timeit(is_primer, x)
    print "It is %r that %d is primer" % (ret, x)

    x = 1111111
    ret = timeit(is_primer, x)
    print "It is %r that %d is primer" % (ret, x)

    x = 1000
    ret = timeit(get_primer_count, x)
    print "It has %d primer in range %d" % (ret, x)

    x = 100000
    ret = timeit(get_primer_count, x)
    print "It has %d primer in range %d" % (ret, x)

if __name__ == "__main__":
    test()
