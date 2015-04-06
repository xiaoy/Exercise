# difference between the sum of the squares of the range of number

def seq_sum(start, end):
    sum = 0
    for i in range(start, end + 1):
        sum += i
    return sum

def seq_sqr_sum(start, end):
    sum = 0
    for i in range(start, end + 1):
        sum += i ** 2
    return sum

def seq_diff(start, end):
    return seq_sum(start, end) ** 2 - seq_sqr_sum(start, end)

print seq_diff(1, 10)
print seq_diff(1, 100)
