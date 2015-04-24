# this program is used to safe input


def safe_input(in_str):
    try:
        out_str = raw_input(in_str)
    except EOFError:
        out_str = None
    except KeyboardInterrupt:
        out_str = None

    return out_str

input_str = safe_input("input your program language you like best:")
if input_str is not None:
    print("the language is:%s is very nice" % (input_str))
else:
    print("you input is None")
