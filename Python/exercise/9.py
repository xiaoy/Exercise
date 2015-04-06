# find Pythagorean triplet

def is_pythagorean_num(a, b, c):
        return ((a ** 2 + b ** 2) == c ** 2)

def find_pythagorean_by_count(count):
    a = 0
    while True:
        if a > count:
            break
        a += 1
        for b in range(a + 1, count):
            for c in range(b + 1, count):
                if not is_pythagorean_num(a, b, c):
                    continue
                elif (a + b + c) == count:
                    return a * b * c

print find_pythagorean_by_count(1000)
