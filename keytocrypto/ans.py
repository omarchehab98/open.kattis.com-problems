from functools import reduce

ciphertext = input()
key = input()
ciphertext = list(map(lambda c: ord(c) - ord('A'), ciphertext))
key = list(map(lambda c: ord(c) - ord('A'), key))
result = ''
for i in range(len(ciphertext)):
    s = (ciphertext[i] - key[i]) % 26
    result += chr(s + ord('A'))
    key += [s]
print(result)