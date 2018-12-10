# Solution is not fast enough for the problem.

def longincsubseq(l):
  if len(l) == 0:
    return []
  m = [1 for i in range(len(l))]
  ci = 0
  for i in range(1, len(l)):
    c = m[i]
    for j in range(0, i):
      if l[i] > l[j] and m[j] + 1 > c:
        c = m[j] + 1
    m[i] = c
    if c > m[ci]:
      ci = i
  lis = [ci]
  c = m[ci] - 1
  while c > 0:
    mc = float('-inf')
    mci = None
    for j in range(0, ci):
      if m[j] == c and l[j] > mc and l[j] < l[lis[0]]:
        mc = l[j]
        mci = j
    lis.insert(0, mci)
    c -= 1
    ci = mci
  return lis


if __name__ == '__main__':
  try:
    i = 0
    while True:
      line = input()
      if i % 2 == 1:
        out = longincsubseq(list(map(int, line.split())))
        print(len(out))
        print(' '.join(map(str, out)))
      i += 1
  except EOFError:
    pass
