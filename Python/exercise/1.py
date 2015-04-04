#this program is used to find multiples 3 and 5 blow 100

num3, num5 = 3, 5
maxNum = 1000

def isMultiples(num):
    if num % num3 == 0 or num % num5 == 0:
        return True
    else:
        return False

answer = 0
for i in range(maxNum):
    if isMultiples(i):
        answer += i

print answer
