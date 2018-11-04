n, m = map(int, input().split())
languages = set(input().split())
translators = [input().split() for i in range(m)]
translators = [(source, target, int(cost)) for (source, target, cost) in translators]
adjacency_list = {"English": set()}
for language in languages:
    adjacency_list[language] = set()
for (source, target, cost) in translators:
    adjacency_list[source].add((target, cost))
    adjacency_list[target].add((source, cost))

total_cost = 0
queue = set(["English"])
while languages:
    change = False
    nodes = []
    for c in queue:
        nodes += list(adjacency_list[c])
    nodes = sorted(nodes)
    for (target, cost) in nodes:
        if target in languages:
            total_cost += cost
            change = True
            languages.remove(target)
            queue.add(target)
    if not change:
        break

print("Impossible" if languages else total_cost)
