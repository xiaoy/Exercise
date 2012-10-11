def gatherDivisors(num) :
    divisors = []
    for d in xrange(1, num/2 +1):
        if(num%d == 0):
            divisors.append(d)
    return divisors
