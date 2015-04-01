# this program to draw a tree, just for fun

def printTreeHead(height):
    for i in range(1, height*2, 2):
        str = (height - i/2) * ' ' + '*' * i
        print(str)

def printTreeTail(height):
    count = height * 2 / 3
    for i in range(count):
        str = (height - 1) * ' ' + '*' * 3
        print(str)

def printTree(height):
    printTreeHead(height)
    printTreeTail(height)


printTree(5)
printTree(10)
