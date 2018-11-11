route = input()
best_encoded_route = len(route)
for i in range(len(route)):
    for j in range(i + 1, len(route)):
        macro = route[i:j]
        encoded_route = route.replace(macro, 'M') + macro
        if len(encoded_route) < best_encoded_route:
            best_encoded_route = len(encoded_route)
print(best_encoded_route)