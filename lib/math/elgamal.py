import random
from datetime import datetime

def gcd(a, b):
  if a == 0:
    return b
  return gcd(b % a, a)

def mult(a, b, m):
  res = 0
  while b:
    if b & 1:
      res = (res + a) % m
    a = (a + a) % m
    b >>= 1
  return res

def modpow(a, b, m):
  res = 1
  while b:
    if b & 1:
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
  if MillerRabin(n):
    return n
  x = x0
  g, q = 1, 1

  m, l = 128, 1
  
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
        q = mult(q, abs(y - x), n)
        i += 1
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
  print('n0', n)
  factors = {}
  for p in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
    n, factors = reduce(n, p, factors)
  if MillerRabin(n, deterministic=False):
    n, factors = reduce(n, n, factors)
  print('n1', n)
  while n != 1 and not MillerRabin(n, deterministic=False):
    f = brent(n)
    print('f', f, 'n', n)
    while not MillerRabin(f, deterministic=False):
      print('brent try')
      x0 = random.randint(2, n - 1)
      c = random.randint(1, n - 1)
      f = brent(n, x0, c)
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
  
def MillerRabin(n, deterministic=True, s=50):
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
    for i in range(s):
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

  def __init__(self, p):
    if not MillerRabin(p):
      print(p, 'is not prime')
      return
    alpha = genPrimitiveRoot(p)
    x  = random.randint(2, p - 2)
    beta = modpow(alpha, x, p)
    
    print('alpha:', alpha)
    print('x:', x)
    print('beta:', beta)


def genPrimeNumber(length=128, tries=1000):
  candidate = random.getrandbits(length)
  i = 0
  while i < tries and not MillerRabin(candidate, deterministic=False):
    candidate = random.getrandbits(length)
    i += 1
  return candidate


random.seed(datetime.now())

eg = ElGamal(13)
p = genPrimeNumber()
#p = 97958148912973598187140994767930068079408933028586068878574252779365218567602843832853390986520395969405157432811350155584613018771062505235567414739372558133314961576854808911356118470496098393336649600663199503487958812262325545485607825037197844087326436024930027070248638029575727459218554606043109194303
#p = 6838639852216922178827358014991492427066835783437527788787442709845021524519904323581223466179368833350296496551173082187924030239755157733393976322266799
print(p)
print(MillerRabin(p, deterministic=False))
print(MillerRabin(4, deterministic=False))
factors = factorize(p - 1)
print(factors)

