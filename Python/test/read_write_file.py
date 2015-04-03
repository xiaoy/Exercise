#this program use to insert user input string to a file

import os

ls = os.linesep

while True:
    fileName = raw_input("input file name:")
    if os.path.isfile(fileName):
        print("the file:", fileName, "have exist.")
    else:
        break

strList = []

print "input '.' in single line to exist"
while True:
    line = raw_input("input the string:")
    if line == '.':
        break
    strList.append(line)

f = open(fileName, 'w')
f.writelines("%s%s" %(s, ls) for s in strList)

f.close()
print("good done")
