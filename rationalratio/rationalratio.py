from fractions import Fraction

x, d = input().split(' ')
d = int(d)
k = len(x) - x.index('.') - d - 1
a, b = x[0:-d].replace('.', ''), 10 ** k
ab = Fraction(int(a), b)
rd = Fraction(int(x[-d:]), (10 ** d - 1) * b)
result = ab + rd
print(str(result.numerator) + '/' + str(result.denominator))
