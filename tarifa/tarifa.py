x = int(input())
n = int(input())
ps = [int(input()) for i in range(n)]
t = x
for p in ps:
  t += x - p
print(t)
