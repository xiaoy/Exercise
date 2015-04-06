#this program use to find the number can divide a range of number

# this is ugly ways to solve this problem
def find_num_div_range(start, end):
    small_num = start
    while True:
        is_find = True
        for i in range(start, end + 1):
            if small_num % i != 0:
                is_find = False
                break
        if is_find:
            return small_num
        else:
            small_num += 1

def gcd(a, b):
    while True:
        n = a % b
        if n == 0:
            return b
        a = b
        b = n

def find_num_div_range_1(start, end):
    small_num = start
    while True:
        for i in range(start, end + 1):
            if small_num % i != 0:
                div = gcd(small_num, i)
                small_num = (small_num * i) / div
        return small_num

find_num_div_range_1(1, 20)
