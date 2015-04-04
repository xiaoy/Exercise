# get the answer of blow 4,000,000 even num sum of fibonacci numbers

a, b = 1, 2
ret = b
while True:
    x = a + b
    if x > 4000000:
        break
    else:
        if x % 2 == 0:
            ret += x
        a = b
        b = x

print ret
