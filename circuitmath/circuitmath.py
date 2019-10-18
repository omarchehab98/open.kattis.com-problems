from collections import namedtuple
A = namedtuple('A', 'x y')
O = namedtuple('O', 'x y')
N = namedtuple('N', 'x')

ops = ['*', '+', '-']
n = int(input())
vs = list(map(lambda x: x == 'T', input().split(' ')))
eq = input().split(' ')

stack = []
for i in eq:
  if i not in ops:
    stack.append(i)
  else:
    if i == '*':
      x = stack.pop()
      y = stack.pop()
      stack.append(A(x, y))
    elif i == '+':
      x = stack.pop()
      y = stack.pop()
      stack.append(O(x, y))
    elif i == '-':
      x = stack.pop()
      stack.append(N(x))

def e(node):
  if isinstance(node, str):
    return vs[ord(node) - 65]
  elif isinstance(node, A):
    return e(node.x) and e(node.y)
  elif isinstance(node, O):
    return e(node.x) or e(node.y)
  elif isinstance(node, N):
    return not e(node.x)
  else:
    raise Exception("wut")

print('T' if e(stack[0]) else 'F')
