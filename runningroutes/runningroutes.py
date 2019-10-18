n = int(input())
g = [list(map(int, input().split(' '))) for i in range(n)]
intervals = []

for i in range(len(g)):
  for j in range(i, len(g)):
    if g[i][j] == 1:
      if abs(i - j) > n / 2:
        intervals.append((j, n + i))
      else:
        intervals.append((i, j))
intervals.sort(key=lambda interval: interval[1])
picked = [intervals[0]]
for interval in intervals[1:]:
  prev = picked[-1]
  if prev[1] < interval[0]:
    picked.append(interval)

print(len(picked))