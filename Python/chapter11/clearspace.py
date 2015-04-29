# this program is used to clear head space and end space in a string


def clear_head_space(line):
    index = 0
    for i, ch in enumerate(line):
        if ch != " ":
            index = i
            break
    return line[index:]


def clear_tail_space(line):
    index = 0
    for i, ch in enumerate(line[::-1]):
        if i == 0:
            continue
        if ch != " ":
            index = i
            break
    return line[:len(line) - index + 1]


def clear_head_and_tail_space(line):
    line = clear_head_space(line)
    line = clear_tail_space(line)
    return line


def clear_file_line_space(path):
    try:
        lines = []
        f = open(path, "r")
        for line in f:
            lines.append(line)
        f.close()

        lines = map(clear_head_and_tail_space, lines)
        f = open(path, "w")
        for line in lines:
            f.write(line)
        f.close()
    except IOError, e:
        print e


def main():
    file_path = raw_input("input your file name:")
    clear_file_line_space(file_path)


if __name__ == "__main__":
    main()
