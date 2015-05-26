# this program is used to generate data
# time::user@domain.com::time(int)-user(int)-domain(int)
# ex:
#   Thu Jul 22 19:21:19 2004::izsp@dicqdhytvhv.edu::1090549279-4-11

from random import randint, choice
from string import lowercase
from time import ctime

doms = ('com', 'edu', 'net', 'org', 'gov')

maxint = 2 ** 31 - 1

for i in range(randint(5, 10)):
    dtint = randint(0, maxint - 1)
    dtstr = ctime(dtint)

    shorter = randint(4, 7)

    em = ''
    for j in range(shorter):
        em += choice(lowercase)

    longer = randint(shorter, 12)

    dm = ''

    for j in range(longer):
        dm += choice(lowercase)

    print("%s::%s@%s.%s::%s-%s-%s" %
          (dtstr, em, dm, choice(doms), dtint, shorter, longer))
