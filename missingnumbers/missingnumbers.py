n = int(input())
prev = 0
good = True
for i in range(n):
  curr = int(input())
  while prev + 1 < curr:
    prev += 1
    print(prev)
    good = False
  prev = curr

if good:
  print("good job")
