rows, cols = map(int, input().split(' '))
grid = []
solution = [[0 for y in range(cols)] for x in range(rows)]
for row in range(rows):
  grid.append(list(map(lambda cell: cell == 'T', input())))

def adjacent(row, col):
  yield (row - 1, col)
  yield (row, col - 1)
  yield (row + 1, col)
  yield (row, col + 1)

# print('\n'.join(map(lambda row: ''.join(map(lambda cell: '' + ('.' if cell else 'T'), row)), grid)))
# print()
depth = 0
dirty = True
while dirty:
  depth += 1
  dirty = False
  for row in range(rows):
    for col in range(cols):
      if grid[row][col]:
        if row == 0 or \
          col == 0 or \
          row == rows - 1 or \
          col == cols - 1:
          dirty = True
          solution[row][col] = depth
        else:
          for y, x in adjacent(row, col):
            if not grid[y][x]:
              dirty = True
              solution[row][col] = depth
  for row in range(rows):
    for col in range(cols):
      if solution[row][col] > 0:
        grid[row][col] = False
  # print('\n'.join(map(lambda row: ''.join(map(lambda cell: '' + ('.' if cell else 'T'), row)), grid)))
  # print()
depth -= 1
print('\n'.join(map(lambda row: ''.join(map(lambda cell: (('..' if cell < 10 else '.') if depth >= 10 else '.') + ('.' if cell == 0 else str(cell)), row)), solution)))
