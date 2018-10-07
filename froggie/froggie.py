import math
l, w = map(int, input().split())
# lanes = [(o, i, s)]
lanes = [list(map(int, input().split())) for i in range(0, l)]
p, moves = input().split()
p, moves = int(p), list(moves)

def move(x, y, move):
    if move == 'U':
        y -= 1
    elif move == 'D':
        y += 1
    elif move == 'L':
        x -= 1
    elif move == 'R':
        x += 1
    return x, y

def collision(x, w, t, lane, is_reverse):
    cars = [False for i in range(0, w)]
    o, i, s = lane
    o = (o + t * s) % w
    while o >= i:
        o -= i
    for c in range(o, w, i):
        cars[c] = True
    safe = [True for i in range(0, w)]
    for c in range(0, w):
        if cars[c]:
            for d in range(c + 1, c + s + 1):
                safe[d % w] = False
    if is_reverse:
        safe.reverse()
    return not safe[x]

x, y, t = p, l, 0
while t < len(moves):
    # move froggie
    x, y = move(x, y, moves[t])
    # break loop if froggie got hit by car in the lane he is in
    if y >= 0 and y < l and collision(x, w, t, lanes[y], y % 2 == 1):
        break
    t += 1

# if froggie crossed the road
if y == -1:
    print("safe")
else:
    print("squish")