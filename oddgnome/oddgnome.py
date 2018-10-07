def get_king_index(gnomes):
    prev = 0
    for curr in range(1, len(gnomes) - 1):
        if (gnomes[prev] != gnomes[curr] - 1):
            return curr + 1
        prev = curr

n = int(input())
for i in range(n):
    gnomes = list(map(int, input().split(' ')))[1:]
    print(get_king_index(gnomes))
