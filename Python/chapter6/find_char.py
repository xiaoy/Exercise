import string

def findchr(str, ch):
    index = 0
    for c in str:
        if c == ch:
            return index
        index += 1
    return -1

def rfindchar(str, ch):
    str = str[::-1]
    index = findchr(str, ch)
    if index == -1:
        return index
    else:
        return len(str) - index - 1

def substr(str, origchar, newchar):
    last_index = -1
    for c in origchar:
        index = findchr(str, c)
        if index != -1:
            if last_index == -1:
                last_index = index
            else:
                if (index - last_index) != 1:
                    last_index = -1
                    break
                last_index = index
        else:
            last_index = -1
            break

    if last_index == -1:
        return str
    else:
        index = last_index - len(newchar) + 2
        return str[0:index] + newchar + str[index + len(newchar):]

# test
str = ''
fstr = 'a'

print 'test findchr'
print str, fstr
print findchr(str, fstr)

print 'test findchr2'
str = string.letters
print str, fstr
print findchr(str, fstr)

print 'test rfindchr'
str = str +'acdef'
print str, fstr
print rfindchar(str, fstr)

print 'test substr'
fstr = 'abc'
rstr = '1111'
print str, fstr, rstr
print substr(str, fstr, rstr)

print 'test substr2'
fstr = 'adc'
rstr = '1111'
print str, fstr, rstr
print substr(str, fstr, rstr)
