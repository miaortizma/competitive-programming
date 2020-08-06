import sys
input = sys.stdin.readline

def gcd(a, b):
  if a == 0:
    return b
  else:
    return gcd(b % a, a)

def le(x, y):
  a, b = x
  c, d = y
  return a * d < b * c

def solve(n):
  #print(n)
  p, v = [], []
  VEC = []
  for i in range(n):
    pi, vi = map(int, input().split())
    p.append(pi)
    v.append(vi)
    VEC.append((pi, vi, i))
  VEC.sort(reverse=True)
    
  s0 = sum([p[i] * v[i] for i in range(n)])
  W = sum(v)
  add = []
  for tup in VEC:
    i = tup[2]
    if le((s0, W), (p[i], 1)):
      W = W + 1
      s0 = s0 - (p[i] * v[i]) + (p[i] * (v[i] + 1))
      add.append(str(i + 1))
  g = gcd(s0, W)
  print('{}/{}'.format(s0 // g, W // g))
  print(len(add))
  print(' '.join(add))
  #print('*' * 10)

t = int(input())
for t in range(t):
  n = int(input())
  solve(n)
