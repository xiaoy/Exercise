# find the largest palindrome product

def print_largest_palindrome(n):
    m = n / 10
    largest = 0
    maxNum = n * n
    for i in range(m, n):
        for j in range(i, n):
            ret = i * j
            if ret <= maxNum:
                str_ret = str(ret)
                if str_ret[::-1] == str_ret and ret > largest:
                    largest = ret
                    last_i, last_j = i, j
    print(largest, last_i, last_j)

print_largest_palindrome(10)
print_largest_palindrome(100)
print_largest_palindrome(1000)

