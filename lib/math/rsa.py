p = 41
q = 53
n = p * q
phi = (p - 1) * (q - 1)

def modpow(a, b, m):
  res = 1
  while (b):
    if (b & 1):
      res = (res * a) % m
    a = (a * a) % m
    b >>= 1
  return res

def gcd(a, b):
  if a == 0:
    return b
  return gcd(b % a, a)

def getKeys(p, q):
  n = p * q
  phi = (p - 1) * (q - 1)
  for i in range(2, phi):
    if gcd(i, phi) == 1: 
      for j in range(2, phi):
        if ((i * j) % n):
          return i, j

e, d = getKeys(p, q)

print('n', n)
print('p', p, 'q', q)
print('phi', phi)
print('e', e, 'd', d)

message = 5
encrypted = modpow(message, e, n)
decrypted = modpow(encrypted, d, n)
print(e, d)
print((e * d) % phi)
print(message, decrypted % n)
