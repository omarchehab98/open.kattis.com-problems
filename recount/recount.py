import sys

ballot = {}
name = sys.stdin.readline()
while name != '***\n':
  if name in ballot:
    ballot[name] += 1
  else:
    ballot[name] = 1
  name = sys.stdin.readline()

best = {
    'name': '',
    'votes': 0
}
is_runoff = False
for name, votes in ballot.items():
  if votes > best['votes']:
    best['name'] = name
    best['votes'] = votes
  elif best['votes'] == votes:
    is_runoff = True
    break

if is_runoff:
  result = 'Runoff!'
else:
  result = best['name']
print(result)
