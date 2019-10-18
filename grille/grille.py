grille = []
size = int(input())
for x in range(size):
  grille.append(list(map(lambda x: x == '.', input())))
ciphertext = input()

def rotate90clockwise(g):
  n = len(g)
  for i in range(n // 2):
    for j in range(i, n - i - 1):
      t = g[i][j] 
      g[i][j] = g[n - 1 - j][i] 
      g[n - 1 - j][i] = g[n - 1 - i][n - 1 - j] 
      g[n - 1 - i][n - 1 - j] = g[j][n - 1 - i] 
      g[j][n - 1 - i] = t 

lookup = []
for i in range(4):
  for x in range(size):
    for y in range(size):
      if grille[x][y]:
        lookup.append(x * size + y)
  rotate90clockwise(grille)

if len(lookup) != size * size or len(set(lookup).intersection(set([i for i in range(size * size)]))) != size * size:
  print("invalid grille")
else:
  plaintext = [None for x in range(size * size)]
  for i in range(size * size):
    plaintext[lookup[i]] = ciphertext[i]
  print(''.join(plaintext))
