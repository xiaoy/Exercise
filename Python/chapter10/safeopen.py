# this program is used to safe open file


def safeopen(path):
    try:
        f = open(path, 'r')
        return f
    except IOError:
        return None


def printf(f):
    for line in f:
        print line,

input_file = raw_input("input file name:")
f = safeopen(input_file)
if f is not None:
    printf(f)
else:
    print("file:%s is not exist" % (input_file))
