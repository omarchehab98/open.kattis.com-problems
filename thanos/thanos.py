import math

n = int(input())

for i in range(0, n):
    (p, r, f) = map(int, input().split(' '))
    y = 0
    while p <= f:
        p = p * r
        y += 1
    print(y)