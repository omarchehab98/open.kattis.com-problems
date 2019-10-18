input()
xs = list(filter(lambda x: x >= 0, map(int, input().split(' '))))
print(sum(xs) / len(xs))
