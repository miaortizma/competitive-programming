import random
from datetime import datetime

def gcd(a, b):
  if a == 0:
    return b
  return gcd(b % a, a)

def modpow(a, b, m):
  res = 1
  while (b):
    if (b & 1):
      res = (res * a) % m
    a = (a * a) % m
    b >>= 1
  return res

def f(x, c, m):
  return ((x * x % m) + c) % m

def eulerPhi(n):
  factors = factorize(n)
  print(factors)
  e = n
  for f in factors:
    e -= e // f
  return e

# finds non trivial factor of number x
def brent(n, x0=2, c=1):
  x = x0
  g = 1
  q = 1
  m = 128
  l = 1
  while g == 1:
    y = x
    for i in range(1, l):
      x = f(x, c, n)
    k = 0
    while (k < l and g == 1):
      xs = x
      i = 0
      while(i < m and i < l - k):
        x = f(x, c, n)
        q = q * abs(y - x) % n
      g = gcd(q, n)
      k += m
    l *= 2
  if g == n:
    xs = f(xs, c, n)
    g = gcd(abs(xs - y), n)
    while g == 1:
      xs = f(xs, c, n)
      g = gcd(abs(xs - y), n)
  return g  

def reduce(n, f, factors):
  if n % f == 0:
    factors[f] = 0
  while n % f == 0:
    n //= f
    factors[f] += 1
  return n, factors

def factorize(n):
  factors = {}
  for p in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
    n, factors = reduce(n, p, factors)
  if MillerRabin(n):
    n, factors = reduce(n, n, factors)
  while n != 1:
    f = brent(n)
    while not MillerRabin(f):
      x0 = random.randint(2, n - 1)
      c = random.randint(1, n - 1)
    n, factors = reduce(n, f, factors)
  return factors

def Witness(n, a, d, s):
  x = modpow(a, d, n)
  if x == 1 or x == n - 1:
    return False
  for r in range(1, s):
    x = x * x % n
    if x == n - 1:
      return False
  return True
  
def MillerRabin(n, deterministic=True, r=50):
  if (n < 2):
    return False
  r = 0
  d = n - 1
  while (d & 1) == 0:
    d >>= 1
    r += 1
  bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
  if not deterministic:
    bases = []
    for i in range(r):
      bases.append(random.randint(2, n - 2))
  for p in bases:
    if n == p:
      return True
    if Witness(n, p, d, r):
      return False
  return True


def PrimitiveRoot(x, phi, p, factors):
  ok = True
  for factor in factors:
    v = modpow(x, phi // factor, p)
    ok &= v != 1
  return ok

def genPrimitiveRoot(p, first=True):
  phi = eulerPhi(p)
  factors = factorize(phi)
  x = random.randint(2, p - 2)
  while not PrimitiveRoot(x, phi, p, factors):
    x = random.randint(2, p - 2)
  return x

class ElGamal:

  def __init__(p):
    if not MillerRabin(p):
      print(p, 'is not prime')
      return
    alpha = genPrimitiveRoot(p)


random.seed(datetime.now())
print(random.random())
