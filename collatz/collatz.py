import sys

def collatz(number, s):
    if number == 1:
        return s

    if number % 2 == 0:
        number = int(number / 2)
        return collatz(number, s + [number])
    else:
        number = 3 * number + 1
        return collatz(number, s + [number])

def first_meet(l1, l2):
    for i1, v1 in enumerate(l1):
        for i2, v2 in enumerate(l2):
            if v1 == v2:
                return {
                    'i1': i1,
                    'i2': i2,
                    'v': v1
                }
    raise Exception()

args = sys.stdin.readline().split(' ')
while int(args[0]) != 0 and int(args[1]) != 0:
    n1 = int(args[0])
    n2 = int(args[1])
    l1 = collatz(n1, [n1])
    l2 = collatz(n2, [n2])
    result = first_meet(l1, l2)
    print (str(n1) + ' needs ' + str(result['i1']) + ' steps, ' + str(n2) + ' needs ' + str(result['i2']) + ' steps, they meet at ' + str(result['v']))
    args = sys.stdin.readline().split(' ')
