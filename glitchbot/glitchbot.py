def move(x, y, direction, instruction):
    if instruction == 'R':
        direction = (direction + 1) % 4
    elif instruction == 'L':
        direction -= 1
        if direction < 0:
            direction = 3
    else:
        if direction == 0:
            y += 1
        elif direction == 1:
            x += 1
        elif direction == 2:
            y -= 1
        else:
            x -= 1
    return x, y, direction

def go(instructions):
    x, y, direction = 0, 0, 0
    for instruction in instructions:
        x, y, direction = move(x, y, direction, instruction)
    return x, y, direction

def fix(instructions, mistake):
    global tX, tY
    fixes = ['R','L','F']
    fixes.remove(instructions[mistake])
    for patch in fixes:
        inst = instructions[:]
        inst[mistake] = patch
        x, y, d = go(inst)
        if (x == tX and y == tY):
            return patch
    return None

def bringitback(c):
    # what a hack
    return {
        'R': 'Right',
        'F': 'Forward',
        'L': 'Left',
    }[c]

tX, tY = list(map(int, input().split(' ')))
instructions = [input()[0] for i in range(int(input()))]

for i in range(len(instructions)):
    instruction = instructions[i]
    theFix = fix(instructions, i)
    if theFix != None:
        print(str(i + 1) + ' ' + bringitback(theFix))
        break
