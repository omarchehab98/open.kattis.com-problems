import math

d, s = map(int, input().split(' '))

def v(d, s, a):
    return a, a * math.cosh(d / (2 * a)) - s

def l(d, a):
    return 2 * a * math.sinh(d / (2 * a))

lo = 0
hi = 125000
a = (hi + lo) / 2
lhs, rhs = v(d, s, a)
while int(lhs * 10e4) != int(rhs * 10e4):
    if lhs > rhs:
        hi = lo + (hi - lo) / 2
    elif lhs < rhs:
        lo = hi - (hi - lo) / 2
    a = (hi + lo) / 2
    lhs, rhs = v(d, s, a)
print(l(d, a))