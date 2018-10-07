n = int(input())
res = 0
probs = []
for i in range(n):
    [ code, prob ] = input().split(' ')
    prob = float(prob)
    probs.append(prob)
probs.sort()
probs = probs[::-1]
for i in range(n):
    prob = probs[i]
    res += prob * (i + 1)

print(res)

