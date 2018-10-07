(p, q, s) = map(int, input().split())

res = False
pc = 0
qc = 0
for i in range(0, s):
    pc = (pc + 1) % p
    qc = (qc + 1) % q
    if pc == 0 and qc == 0:
        res = True
        break

if res:
    print("yes")
else:
    print("no")
