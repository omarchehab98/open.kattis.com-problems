def parseBallot(line):
  p, ballot = line.split()
  return int(p), dict(zip(map(lambda x: ord(x) - ord('A'), ballot), list(range(len(ballot)))))

n, m = map(int, input().split())
ballots = list(map(parseBallot, [input() for _ in range(m)]))

graph = dict(zip(list(range(n)), [set() for _ in range(n)]))
for v in range(n):
  for w in range(v + 1, n):
    i_p, j_p = 0, 0
    for p, ballot in ballots:
      if ballot[v] < ballot[w]:
        i_p += p
      else:
        j_p += p
    graph[v].add(w) if i_p > j_p else graph[w].add(v)

reversed_graph = dict(zip(list(range(n)), [set() for _ in range(n)]))
for v in graph.keys():
  for w in graph.keys():
    if v != w and v in graph[w]:
      reversed_graph[v].add(w)

def dfs(graph, v, visited):
  visited.add(v)
  for w in graph[v]:
    if w not in visited:
      dfs(graph, w, visited)

for i in range(n):
  beats = set()
  dfs(graph, i, beats)
  beaten_by = reversed_graph[i]
  print("{}: can{} win".format(chr(ord('A') + i), '' if beaten_by.issubset(beats) else "'t"))
