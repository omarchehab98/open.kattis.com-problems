n, t = map(int, input().split(' '))
positions = [list(map(int, input().split(' '))) for i in range(n)]
gpsPositions = [ positions[0] ]
maxT = positions[-1][2]

actualTIndex = 1
prevActualT = 0
currT = t
while currT < maxT:
    actualT = positions[actualTIndex][2]
    while currT > actualT:
        actualTIndex += 1
        prevActualT = actualT
        actualT = positions[actualTIndex][2]
    delta = (currT - prevActualT) / (actualT - prevActualT)
    currX, currY, _ = positions[actualTIndex]
    prevX, prevY, _ = positions[actualTIndex - 1]
    gpsPositions.append([
        (currX - prevX) * delta,
        (currY - prevY) * delta,
        currT,
    ])
    xOff, yOff, _ = positions[actualTIndex - 1]
    gpsPositions[-1][0] += xOff
    gpsPositions[-1][1] += yOff
    currT += t

gpsPositions.append(positions[-1])

def calculate_total_distance(positions, maxT):
    distance = 0
    curr = 1
    while curr < len(positions):
        prevX, prevY, prevT = positions[curr - 1]
        x, y, t = positions[curr]
        distance += ((x - prevX) ** 2 + (y - prevY) ** 2) ** 0.5
        curr += 1
    return distance

actualDistance = calculate_total_distance(positions, maxT)
gpsDistance = calculate_total_distance(gpsPositions, maxT)
percentageLost = ((actualDistance - gpsDistance) / actualDistance) * 100
print(percentageLost)
