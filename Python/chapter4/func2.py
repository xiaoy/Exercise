# this program used for multiple arguments

# arguments list
def logList(*strList):
    for s in strList:
        print(s)

logList("hello", "world")

# arguments dictionary
def logDic(**strDic):
    for s in strDic.keys():
        print(s, strDic[s])

logDic(hello="world", nice="c++")

# unpack arguments
d = {"1":"c++", "2":"java", "3":"python"}
logDic(**d)

# default arguments
def logDefault(width = 1, *strList):
    for s in strList:
        print(width * '*', s)

logDefault(4, 'python', 'is', 'best', 'name')
