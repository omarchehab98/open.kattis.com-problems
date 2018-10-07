from collections import deque

n = int(input())
moves = input()
d = deque([1])
path = []
i = 0

while i < len(moves):
    if moves[i] == 'L':
        d.appendleft(i + 2)
    if i >= len(moves) - 1 or moves[i] != moves[i + 1]:
        path += d
        d = deque()
    if moves[i] == 'R':
        d.append(i + 2)
    i += 1

print('\n'.join(map(str, path + list(d))))
