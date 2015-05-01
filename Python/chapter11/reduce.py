# this program is used to exercise reduce function
import time


def mul(x, y):
    return x * y


def factorial(n):
    return reduce(mul, [i for i in range(2, n + 1)])


def factorial_l(n):
    return reduce(lambda x, y: x * y, [i for i in range(2, n + 1)])


def test_it(func, n):
    time_now = time.time()
    ret = func(n)
    det_time = time.time() - time_now

    print "the %s run result is:%d, use time:%d" \
        % (func.__name__, ret, det_time)


def test():
    n = 5
    test_it(factorial, n)
    test_it(factorial_l, n)

    n = 20
    test_it(factorial, n)
    test_it(factorial_l, n)


if __name__ == "__main__":
    test()
