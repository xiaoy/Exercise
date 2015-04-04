# find the largest palindrome product

def print_largest_palindrome(n):
    m = n / 10
    maxLen = len(str((n - 1) * (n -1)))
    detLen = maxLen / 2
    largest = 0
    for i in range(m, n):
        for j in range(i, n):
            ret = i * j
            ret = str(ret)
            if len(ret) == maxLen:
                if ret[::-1] == ret:
                    largest = ret
                    last_i, last_j = i, j
    print(largest, last_i, last_j)

print_largest_palindrome(100)
print_largest_palindrome(1000)

