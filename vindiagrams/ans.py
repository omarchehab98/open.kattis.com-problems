from sys import setrecursionlimit

setrecursionlimit(10000)

r, c = map(int, input().split())
grid = [list(input()) for i in range(r)]
intersections = []
A = None
B = None
for i in range(r):
    for j in range(c):
        if grid[i][j] == 'A':
            A = (i, j)
        elif grid[i][j] == 'B':
            B = (i, j)
        elif i > 0 and j > 0 and \
            i < r - 1 and j < c - 1 and \
            grid[i][j] == 'X' and \
            grid[i - 1][j] == 'X' and \
            grid[i + 1][j] == 'X' and \
            grid[i][j - 1] == 'X' and \
            grid[i][j + 1] == 'X':
            intersections += [(i, j)]

def flood_replace_stop_at_coords(i, j, replace_from, replace_to, stop_at0, stop_at1):
    global grid, r, c
    if i < 0 or j < 0 or i >= r or j >= c or \
        (i == stop_at0[0] and j == stop_at0[1]) or \
        (i == stop_at1[0] and j == stop_at1[1]):
        return
    if grid[i][j] == replace_from:
        grid[i][j] = replace_to
        flood_replace_stop_at_coords(i - 1, j, replace_from, replace_to, stop_at0, stop_at1)
        flood_replace_stop_at_coords(i + 1, j, replace_from, replace_to, stop_at0, stop_at1)
        flood_replace_stop_at_coords(i, j - 1, replace_from, replace_to, stop_at0, stop_at1)
        flood_replace_stop_at_coords(i, j + 1, replace_from, replace_to, stop_at0, stop_at1)

flood_replace_stop_at_coords(A[0] - 1, A[1], 'X', 'A', intersections[0], intersections[1])
flood_replace_stop_at_coords(A[0] + 1, A[1], 'X', 'A', intersections[0], intersections[1])
flood_replace_stop_at_coords(A[0], A[1] - 1, 'X', 'A', intersections[0], intersections[1])
flood_replace_stop_at_coords(A[0], A[1] + 1, 'X', 'A', intersections[0], intersections[1])

flood_replace_stop_at_coords(B[0] - 1, B[1], 'X', 'B', intersections[0], intersections[1])
flood_replace_stop_at_coords(B[0] + 1, B[1], 'X', 'B', intersections[0], intersections[1])
flood_replace_stop_at_coords(B[0], B[1] - 1, 'X', 'B', intersections[0], intersections[1])
flood_replace_stop_at_coords(B[0], B[1] + 1, 'X', 'B', intersections[0], intersections[1])

x_i, x_j = intersections[0]
if grid[x_i - 1][x_j] == 'A':
    flood_replace_stop_at_coords(x_i + 1, x_j, 'X', 'A', intersections[0], intersections[1])
elif grid[x_i + 1][x_j] == 'A':
    flood_replace_stop_at_coords(x_i - 1, x_j, 'X', 'A', intersections[0], intersections[1])
elif grid[x_i][x_j - 1] == 'A':
    flood_replace_stop_at_coords(x_i, x_j + 1, 'X', 'A', intersections[0], intersections[1])
elif grid[x_i][x_j + 1] == 'A':
    flood_replace_stop_at_coords(x_i, x_j - 1, 'X', 'A', intersections[0], intersections[1])

if grid[x_i - 1][x_j] == 'B':
    flood_replace_stop_at_coords(x_i + 1, x_j, 'X', 'B', intersections[0], intersections[1])
elif grid[x_i + 1][x_j] == 'B':
    flood_replace_stop_at_coords(x_i - 1, x_j, 'X', 'B', intersections[0], intersections[1])
elif grid[x_i][x_j - 1] == 'B':
    flood_replace_stop_at_coords(x_i, x_j + 1, 'X', 'B', intersections[0], intersections[1])
elif grid[x_i][x_j + 1] == 'B':
    flood_replace_stop_at_coords(x_i, x_j - 1, 'X', 'B', intersections[0], intersections[1])

grid_A = [[(grid[i][j] if grid[i][j] != 'B' else '.') for j in range(c)] for i in range(r)]
grid_B = [[(grid[i][j] if grid[i][j] != 'A' else '.') for j in range(c)] for i in range(r)]

class ReachedBoundaryException(Exception):
    pass

def flood_replace_stop_at_character(i, j, grid, replace_from, replace_to, stop_at):
    global r, c
    if i < 0 or j < 0 or i >= r or j >= c:
        raise ReachedBoundaryException("reached boundary")
    if grid[i][j] in stop_at:
        return
    if grid[i][j] == replace_from:
        grid[i][j] = replace_to
        flood_replace_stop_at_character(i - 1, j, grid, replace_from, replace_to, stop_at)
        flood_replace_stop_at_character(i + 1, j, grid, replace_from, replace_to, stop_at)
        flood_replace_stop_at_character(i, j - 1, grid, replace_from, replace_to, stop_at)
        flood_replace_stop_at_character(i, j + 1, grid, replace_from, replace_to, stop_at)

out_A = None
if grid_A[x_i - 1][x_j] == '.':
    try:
        flood_replace_stop_at_character(x_i - 1, x_j, grid_A, '.', 'M', set(['A', 'X']))
    except ReachedBoundaryException:
        out_A = 'M'
    try:
        flood_replace_stop_at_character(x_i + 1, x_j, grid_A, '.', 'N', set(['A', 'X']))
    except ReachedBoundaryException:
        out_A = 'N'
elif grid_A[x_i][x_j - 1] == '.':
    try:
        flood_replace_stop_at_character(x_i, x_j - 1, grid_A, '.', 'M', set(['A', 'X']))
    except ReachedBoundaryException:
        out_A = 'M'
    try:
        flood_replace_stop_at_character(x_i, x_j + 1, grid_A, '.', 'N', set(['A', 'X']))
    except ReachedBoundaryException:
        out_A = 'N'
out_B = None
if grid_B[x_i - 1][x_j] == '.':
    try:
        flood_replace_stop_at_character(x_i - 1, x_j, grid_B, '.', 'M', set(['B', 'X']))
    except ReachedBoundaryException:
        out_B = 'M'
    try:
        flood_replace_stop_at_character(x_i + 1, x_j, grid_B, '.', 'N', set(['B', 'X']))
    except ReachedBoundaryException:
        out_B = 'N'
elif grid_B[x_i][x_j - 1] == '.':
    try:
        flood_replace_stop_at_character(x_i, x_j - 1, grid_B, '.', 'M', set(['B', 'X']))
    except ReachedBoundaryException:
        out_B = 'M'
    try:
        flood_replace_stop_at_character(x_i, x_j + 1, grid_B, '.', 'N', set(['B', 'X']))
    except ReachedBoundaryException:
        out_B = 'N'

in_A = 'M' if out_A == 'N' else 'N'
in_B = 'M' if out_B == 'N' else 'N'

area_A = 0
area_B = 0
area_A_B = 0
area_B_line_in_A = 0
area_A_line_in_B = 0

for i in range(r):
    for j in range(c):
        if grid_A[i][j] == in_A:
            area_A += 1
        if grid_B[i][j] == in_B:
            area_B += 1
        if grid_A[i][j] == in_A and grid_B[i][j] == in_B:
            area_A_B += 1
        if grid_A[i][j] == in_A and grid_B[i][j] == 'B':
            area_B_line_in_A += 1
        if grid_A[i][j] == 'A' and grid_B[i][j] == in_B:
            area_A_line_in_B += 1

print(str(area_A - area_A_B - area_B_line_in_A) + " " + str(area_B - area_A_B - area_A_line_in_B) + " " + str(area_A_B))
