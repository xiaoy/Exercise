__author__ = 'wulongfei'
#list function
a = [62, 34, 1, 57, 9, 6, 9]

print(a)

print(a.count(1))

a.reverse()
print(a)

print(a.index(1))

print(a.pop())

a.sort()
print(a)

# list comprehensions
sequences =[]

for x in range(10):
    sequences.append(x**2)

print(sequences)

sequences = [x**3 for x in range(10)]

print(sequences)

sequences = [(x,y) for x in [1, 2, 3] for y in [3, 4, 2] if x != y]

print(sequences)

# dictionary

dic = {x:x*x for x in range(10)}
for k, v in dic.items():
    print(k, v)

print(dic.keys())

print(dic.values())

print(dic.items())
