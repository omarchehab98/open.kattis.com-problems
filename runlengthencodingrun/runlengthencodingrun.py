import re

(op, s) = input().split()

out = ''
if op == 'E':
    c = 1
    prev = s[0]
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            c += 1
        else:
            out += prev + str(c)
            c = 1
            prev = s[i]
    out += prev + str(c)
elif op == 'D':
    for i in range(0, len(s)):
        if (re.search('\d', s[i])):
            out += s[i - 1] * (int(s[i]) - 1)
        else:
            out += s[i]
print (out)