from functools import reduce

def char_to_int(c):
    return 0 if ' ' == c else ord(c) - 96

def int_to_char(i):
    return [
        ' ',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    ][i]

def encrypt(text):
    integers = list(map(char_to_int, text))
    prev = None
    for curr in range(len(integers)):
        if curr > 0:
            integers[curr] += integers[prev]
        prev = curr
    return ''.join(list(map(lambda x: int_to_char(x % 27), integers)))


def decrypt(ciphertext):
    integers = list(map(char_to_int, ciphertext))
    prev, prevVal = None, None
    for curr in range(len(integers)):
        prevValBeforeChange = integers[curr]
        if curr > 0:
            integers[curr] -= prevVal
        prevVal = prevValBeforeChange
        prev = curr
    return ''.join(list(map(lambda x: int_to_char(x % 27), integers)))


n = int(input())
for i in range(n):
    method, text = input().split(' ', 1)
    print(encrypt(text) if method == 'e' else decrypt(text))