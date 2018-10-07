n = int(input())
characters = {
  '0': 0,
  '1': 1,
  '2': 2,
  '3': 3,
  '4': 4,
  '5': 5,
  '6': 6,
  '7': 7,
  '8': 8,
  '9': 9,
  'A': 10,
  'C': 11,
  'D': 12,
  'E': 13,
  'F': 14,
  'H': 15,
  'J': 16,
  'K': 17,
  'L': 18,
  'M': 19,
  'N': 20,
  'P': 21,
  'R': 22,
  'T': 23,
  'V': 24,
  'W': 25,
  'X': 26
}
fix = {
  'B': '8',
  'G': 'C',
  'I': '1',
  'O': '0',
  'Q': '0',
  'S': '5',
  'U': 'V',
  'Y': 'V',
  'Z': '2'
}
checksum_method = [ 2, 4, 5, 7, 8, 10, 11, 13 ]

for i in range(n):
  [ k, code ] = input().split(' ')
  for key in fix:
    code = code.replace(key, fix[key])
  checksum_real = characters[code[-1]]
  code = code[:-1]
  rev_code = code[::-1]
  result = 0
  checksum = 0
  index = 0
  for char in rev_code:
    result += characters[char] * (27 ** index)
    checksum += checksum_method[index] * characters[code[index]]
    index += 1
  checksum = checksum % 27
  if checksum == checksum_real:
    print(k + ' ' + str(result))
  else:
    print(k + ' Invalid')

