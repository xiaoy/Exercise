# this program is used to test os
import os


def main():
    os.system("ls -al")

    ret = eval('1+2')
    print ret

    exec "print 'hello, world'"

if __name__ == "__main__":
    main()
