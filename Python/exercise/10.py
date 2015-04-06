# find the sum of prime
import math
def sum_prime_by_count(num):
    pp = 3
    tp = [pp]
    ret = 2
    while True:
        if pp > num:
            break
        test=True
        sqrtpp = math.sqrt(pp)
        for a in tp:
            if a > sqrtpp: break
            if pp%a == 0:
                test = False
                break
        if test:
            tp.append(pp)
            ret += pp
        pp += 2
    return ret

print sum_prime_by_count(11)

print sum_prime_by_count(2000000)
