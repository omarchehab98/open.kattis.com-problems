from math import log, ceil, floor

def ssd(b, n):
  s = 0
  ds = ceil(log(n, b))
  for d in range(ds, -1, -1):
    m = b ** d
    w = floor(n / m)
    n -= m * w
    s += w ** 2
  return s

p = int(input())
for i in range(p):
  k, b, n = map(int, input().split(' '))
  print(k, ssd(b, n))
