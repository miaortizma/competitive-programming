import math
#import sys

#input = sys.stdin.readline

def getPrimes(N):
  primes = []
  #print(int(math.sqrt(N)) // 2 + 10)
  isPrime = [True] * (int(math.sqrt(N)) // 2 + 1)

  primes.append(2)
  i = 3
  while i * i <= N:
    iid = i // 2 - 1
    if isPrime[iid]:
      primes.append(i)
      j = 3 * i
      while j * j <= N:
        jid = j // 2 - 1
        isPrime[jid] = False
        j += 2 * i
    i += 2
  return primes

def factorize(primes, n):
  factors = []
  
  return factors

def mult(A, B, mod):
  n = len(A)
  K = len(A[0])
  m = len(B[0])
  C = [[0 for i in range(m)] for j in range(n)]
  for i in range(n):
    for j in range(m):
      for k in range(K):
        C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % mod) % mod
  return C

def fastFib(N, m):
  if N == 0:
    return 0
  if N == 1:
    return 1
  mat = [[0, 1], [1, 1]]
  v = [[0, 1]]

  N -= 2
  #print(N)
  while N:
    if N & 1:
      v = mult(v, mat, m)
    mat = mult(mat, mat, m)
    N >>= 1
  return v[0][1]

def isPrimePeriod(p, r):
  a = fastFib(r, p)
  b = fastFib(r + 1, p)
  return a == 1 and b == 0

def getPrimePeriod(p):
  #print('prime: ', p)
  candidates = [p // 2, p - 1, p + 1, p * 2 + 2, p * 4]
  for candidate in candidates:
    if candidate <= 1:
      continue
    if isPrimePeriod(p, candidate):
      return candidate
  return -1


def printr(fib, m, r):
  print()
  print(m, r)
  n = len(fib)
  if r == m * 2 + 2:
    print('m * 2 + 2')
  if r == m * 2 - 2:
    print('m * 2 - 2')
  if r == m - 1:
    print('m - 1')
  
  nn = n // r
  for i in range(min(2, nn)):
    for j in range(r):
      #print(i * m + j)
      print(fib[i * r + j] % m, end=' ')
    print(' ')

primes = getPrimes(int(1e12))
fib = [0, 1]


n = 5000
for i in range(n):
  fib.append(fib[-1] + fib[-2])

#print(getPrimePeriod(2))
printr(fib, 47, 32)
T = int(input())
for i in range(2, int(1e4)):
  n = int(input())
  #n = i
  oldn = n
  T -= 1
  r = 1
  for i, p in enumerate(primes):
    if p > n:
      break
    if n % p == 0:
      print('prime :', p)
      r *= getPrimePeriod(p)
      print('r', r)
      n //= p
      while n % p == 0:
        r *= p
        n //= p
        print('r', r)
  if n != 1:
    r *= getPrimePeriod(n)
  if not isPrimePeriod(oldn, r):
    print(oldn, r)
  print(r)
  printr(fib, oldn, r)



