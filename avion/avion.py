dirty = False
for i in range(5):
  if "FBI" in input():
    print(i + 1)
    dirty = True

if not dirty:
  print("HE GOT AWAY!")