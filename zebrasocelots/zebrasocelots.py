n = int(input())
m = [input() == "Z" for i in range(0, n)]

def ans(n, m):
    l = 0
    for k in m:
        l = (l << 1) + k
    return 2 ** n - 1 - l

print(ans(n, m))
