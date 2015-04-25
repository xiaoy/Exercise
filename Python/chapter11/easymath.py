# this program is design for our child to play easy math

from operator import add, sub, mul, div
from random import randint, choice


ops = {"+": add, "-": sub, "*": mul, "/": div}
MAX_TRIES = 2


def doprob():
    op = choice("+-*/")
    nums = [randint(1, 10) for i in range(2)]
    nums.sort(reverse=True)
    ans = ops[op](*nums)

    pr = "%d %s %d = " % (nums[0], op, nums[1])

    tryTimes = 0

    while True:
        try:
            if ans == int(raw_input(pr)):
                print "correct"
                break

            if tryTimes == MAX_TRIES:
                print "answer\n%s%d" % (pr, ans)
                break
            else:
                print "incorrect, try again"
                tryTimes += 1
        except (KeyboardInterrupt, EOFError, ValueError):
            print "invalid input, try again"


def main():
    while True:
        doprob()
        try:
            opt = raw_input("Again? [y]").lower()
            if opt and opt[0] == 'n':
                break
        except (KeyboardInterrupt, EOFError):
            break


if __name__ == '__main__':
    main()
