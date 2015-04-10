# matrix test

def add(m1, m2):
    if len(m1) != len(m2) or len(m1[0]) != len(m2[0]):
        print 'the input matrix is not same pattern'
        return None

    for i in range(len(m1)):
        for j in range(len(m1[i])):
            m1[i][j] += m2[i][j]
    return m1

def dot(m1, m2):
    if len(m1[0]) != len(m2):
        print 'can not play dot multiply'
        return None

    m = []
    for i in range(len(m1)):
        m_row = []
        for j in range(len(m2[0])):
            ret = 0
            for q in range(len(m2)):
                ret += m1[i][q] * m2[q][j]
            m_row.append(ret)
        m.append(m_row)

    return m



def printM(m):
    for i in range(len(m)):
        for j in range(len(m[i])):
            print m[i][j],
        print '\n'


# test add
m1 = [[1, 2, 3],
      [2, 1, 4],
      [4, 5, 7]]

m2 = [[3, 4, 5],
      [1, 2, 4],
      [-1, 2, 3]]
printM(m1)
print '-' * 40
printM(m2)
print '-' * 40
printM(add(m1, m2))


# test dot
print '-' * 40
m1 = [[1, 2, 3],
      [4, 5, 6]]

m2 = [[7, 8],
      [9, 10],
      [11, 12]]

printM(m1)
print '-' * 40
printM(m2)
print '-' * 40
printM(dot(m1, m2))
