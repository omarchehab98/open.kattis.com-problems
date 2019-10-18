P, D = list(map(int, input().split(' ')))
totA, totB = 0, 0
dis = [[0,0,0,0] for i in range(D)]
for i in range(P):
  a, b, c = map(int, input().split(' '))
  
  k = (b+c)//2 + 1
  
  dis[a-1][0] += b 
  dis[a-1][1] += c

for i, (ta, tb, _, _) in enumerate(dis):
  k = (ta + tb)//2 + 1
  if ta > tb:
    wA = ta-k
    wB = tb
  else:
    wA = ta
    wB = tb-k
  dis[i][2] = wA
  dis[i][3] = wB
  print('A' if ta > tb else 'B', f"{wA} {wB}")

tot = sum(a[0] + a[1] for a in dis)
wA = sum(a[2] for a in dis)
wB = sum(a[3] for a in dis)
print(abs(wA - wB) / tot)
