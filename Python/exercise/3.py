# find the max prime factor

def maxPrimer(n):
    d = 2
    while n > 1:
        while n % d == 0:
            n /= d
            ret = d
        d = d + 1
    print ret
maxPrimer(13195)
maxPrimer(600851475143)
