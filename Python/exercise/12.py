# find the triangular number that have 500,000,000
import operator
# A slightly efficient superset of primes.


def PrimesPlus():
  yield 2
  yield 3
  i = 5
  while True:
    yield i
    if i % 6 == 1:
      i += 2
    i += 2


# Returns a dict d with n = product p ^ d[p]
def GetPrimeDecomp(n):
  d = {}
  primes = PrimesPlus()
  for p in primes:
    while n % p == 0:
      n /= p
      d[p] = d.setdefault(p, 0) + 1
    if n == 1:
      return d


def NumberOfDivisors(n):
  d = GetPrimeDecomp(n)
  powers_plus = map(lambda x: x+1, d.values())
  return reduce(operator.mul, powers_plus, 1)


max_divitor = 500


def get_tri_num(n):
    return (n * (n + 1)) / 2


def get_divitor_count(n):
    count = 1
    limit = n
    for i in range(1, limit):
        if n % i == 0:
            limit = n / i
            if limit != i:
                count += 1
    return count + 1

n = 1
while True:
    tri_n = get_tri_num(n)
    #if get_divitor_count(tri_n) >= max_divitor:
    if NumberOfDivisors(tri_n) >= max_divitor:
        break
    n = n + 1


print get_tri_num(n)
