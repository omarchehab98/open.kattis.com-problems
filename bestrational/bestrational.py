from fractions import Fraction

def bestrational(m, x):
  return Fraction(x).limit_denominator(m)

n = int(input())
for i in range(n):
  k, m, x = [f(x) for f, x in zip([int, int, str], input().split(' '))]
  print(k, bestrational(m, x))
