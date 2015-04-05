# this program is initiate a sample calculate

def op_ret(op, a, b):
    a, b = int(a), int(b)
    if op == '+':
        print('%d + %d = %d'%(a, b, a + b))
    elif op == '-':
        print('%d - %d = %d'%(a, b, a - b))
    elif op == '*':
        print('%d * %d = %d'%(a, b, a * b))
    elif op == '/':
        print('%d / %d = %d'%(a, b, a / b))
    else:
        print("the operate is not exist")

op_list = ['+', '-', '*', '/']
while True:
    input_str = raw_input("input your expression:")
    isFindOp = False
    for op in op_list:
        input_str = input_str.strip(' ')
        index = input_str.find(op)
        if index > 0:
            a = input_str.split(op, 1)
            op_ret(op, a[0], a[1])
            isFindOp = True
            break
    if not isFindOp:
        print("the expression is wrong")

