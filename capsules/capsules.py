rn, cn = map(int, input().split(' '))

def adjacent(r, c):
  global cells, rn, cn
  if c + 1 < cn:
    yield cells[r][c + 1]
  if c - 1 >= 0:
    yield cells[r][c - 1]
  if r + 1 < rn:
    yield cells[r + 1][c]
  if r + 1 < rn and c + 1 < cn:
    yield cells[r + 1][c + 1]
  if r + 1 < rn and c - 1 >= 0:
    yield cells[r + 1][c - 1]
  if r - 1 >= 0:
    yield cells[r - 1][c]
  if r - 1 >= 0 and c + 1 < cn:
    yield cells[r - 1][c + 1]
  if r - 1 >= 0 and c - 1 >= 0:
    yield cells[r - 1][c - 1]

def idx(d, xs):
  r = d
  for x in xs:
    r = r[x]
  return r

class Cell:
  def __init__(self, row, col, value):
    self.row = row
    self.col = col
    self.value = value
    self.region = None
    self.impossible_values = set()

  def possible_values(self):
    if self.value != None:
      return set()
    vs = self.region.remaining_values(). \
      difference( \
        set([cell.value for cell in adjacent(self.row, self.col)]))
    return vs.difference(self.impossible_values)

  def __str__(self):
    return "cells[{}][{}]: value={}, region.key={}".format(self.row, self.col, self.value, self.region.key)

class Region:
  def __init__(self, key, cells):
    self.key = key
    self.cells = cells
    for cell in cells:
      cell.region = self

  def remaining_values(self):
    remaining_values = set(range(1, len(self.cells) + 1)). \
      difference( \
        set(map(lambda cell: cell.value, self.cells)))
    return remaining_values

  def remaining_values_counts(self):
    remaining_values_counts = {}
    for cell in self.cells:
      possible_values = cell.possible_values()
      for value in possible_values:
        remaining_values_counts[value] = remaining_values_counts.get(value, 0) + 1
    return remaining_values_counts

cells = []
target = rn * cn
for r in range(rn):
  cells.append([])
  line = input().split(' ')
  for c in range(cn):
    v = int(line[c]) if line[c] != '-' else None
    if v != None:
      target -= 1
    cells[r].append(Cell(r, c, v))

regions = []
for i in range(int(input())):
  line = input().split(' ')
  region = Region(i, list(map(lambda x: idx(cells, map(lambda x: int(x) - 1, x[1:-1].split(','))), line[1:])))
  regions.append(region)

prev_target = None
while target > 0:
  for r in range(rn):
    for c in range(cn):
      cell = cells[r][c]
      if cell.value == None:
        # If only one possible number can go into this cell
        possible_values = cell.possible_values()
        if len(possible_values) == 1:
          (value,) = possible_values
          # print("SET {} {} = {}".format(r, c, value))
          cell.value = value
          target -= 1

      if cell.value == None:
        # If this cell can hold a number that no other cell in the region can hold
        remaining_values_counts = cell.region.remaining_values_counts()
        for value in cell.possible_values():
          if remaining_values_counts[value] == 1:
            # print("SET {} {} = {}".format(r, c, value))
            cell.value = value
            target -= 1

      if cell.value == None:
        # If this cell can hold a number that prevents the completion of other regions
        impossible_values = set()
        possible_values = cell.possible_values()
        for possible_value in possible_values:
          regions_remaining_values = {}
          for adjacent_cell in adjacent(cell.row, cell.col):
            if adjacent_cell.region.key not in regions_remaining_values:
              regions_remaining_values[adjacent_cell.region.key] = adjacent_cell.region.remaining_values_counts()
          for adjacent_cell in adjacent(cell.row, cell.col):
            if possible_value in adjacent_cell.possible_values():
              region_remaining_values = regions_remaining_values[adjacent_cell.region.key]
              if possible_value in region_remaining_values:
                region_remaining_values[possible_value] -= 1
                if region_remaining_values[possible_value] == 0:
                  impossible_values.add(possible_value)
        if len(impossible_values) > 0:
          cell.impossible_values.update(impossible_values)
          prev_target = None

  if prev_target == target:
    print("try harder")
    break
  prev_target = target

# print('\n\n'.join(['\n'.join(map(str, row_cells)) for row_cells in cells])) # DEBUG
print('\n'.join([' '.join(map(lambda cell: str(cell.value), row_cells)) for row_cells in cells]))
