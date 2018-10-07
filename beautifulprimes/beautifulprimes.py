p = []
MAXN = 1000000

def gen_primes():
    mn = [0] * 1000010
    for i in range(2, MAXN):
        if(mn[i] == 0):
            p.append(i)
        for j in range(len(p)):
            if(p[j] * i > MAXN):
                break
            mn[p[j]*i] = p[j]
            if(i % p[j] == 0):
                break

def get_prime(i):
    return p[i]

def ans(n):
    prime = 2
    prod = 2
    pi = 0
    while len(str(prod)) < n:
        prime = get_prime(pi)
        prod = prime ** n
        pi += 1
    if len(str(prod)) == n:
        return [prime] * n
    m = 1
    prev_prime = get_prime(pi - 2)
    while len(str(prod)) > n:
        prod = int(prime ** (n - m)) * int(prev_prime ** m)
        m += 1
    return ([prime] * (n - m)) + ([prev_prime] * m)

t = int(input())
gen_primes()
for i in range(0, t):
    n = int(input())
    print(' '.join(map(str, ans(n))))