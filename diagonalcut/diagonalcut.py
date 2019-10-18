def gcd(a, b):
  while b != 0:
    a, b = b, a % b
  return a

[a, b] = list(map(int, input().split(' ')))
d = gcd(a, b)
if(((a // d) % 2 == 1) and ((b // d) % 2 == 1) ):
  print(d)
else:
  print(0)
