for i in range(int(input())):
  x = int(input())
  r = 1
  for j in range(2, x + 1):
    r *= j
  print(str(r)[-1])
