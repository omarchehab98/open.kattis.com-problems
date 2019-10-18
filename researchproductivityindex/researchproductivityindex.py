n = int(input())
ps = sorted(list(map(int, input().split(' '))), reverse=True)
ps = [i / 100 for i in ps]

def score(a, n):
  if a == 0:
    return 0
  else:
    return a ** (a / n)

prev = ps[0]
arr = [ps[0], 1-ps[0]]
for i in range(1, n):
  c = ps[i]
  tmp = [arr[0] * c]
  for j in range(i):
    tmp.append(arr[j]*(1-c) + arr[j+1]*c)
  tmp.append(arr[j+1]*(1-c))
  arr = tmp
  sc = sum([arr[j] * score(i+1-j, i+1) for j in range(len(arr))])
  if sc >= prev:
    prev = sc
  

print(f"{prev}")