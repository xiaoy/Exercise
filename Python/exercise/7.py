# find the prime of the index

def get_prime_by_index(index):
    n = 2
    count = 0
    while True:
        if count == index:
            break
        if is_primer(n):
            count += 1
        n += 1
    return (n - 1)

def is_primer(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True


print get_prime_by_index(6)
print get_prime_by_index(10001)
