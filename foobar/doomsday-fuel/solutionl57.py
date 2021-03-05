from fractions import Fraction
import math

def gcd(a, b):
  if a == 0:
    return b
  else:
    return gcd(b % a, a)

def power(m, n):
  A = identity(len(m))
  B = m
  while n:
    if (n & 1):
      A = multp(A, B)
    B = multp(B, B)
    n >>= 1
  return B

def multp(A, B):
  n, m, K = len(A), len(B[0]), len(A[0])
  C = [[0  for j in range(m)] for i in range(n)]
  for i in range(n):
    for j in range(m):
      for k in range(K):
        C[i][j] += A[i][k] * B[k][j]
      a = C[i][j].numerator
      b = C[i][j].denominator
      lim = (1 << 128) - 1
      C[i][j] = C[i][j].limit_denominator(lim)
  return C

def normalize(v):
  lcm = 1
  for vi in v:
    a = vi.numerator
    b = vi.denominator
    if vi != 0:
      g = gcd(lcm, b)
      lcm = (lcm * b) // g
  sol = []
  for vi in v:
    a = vi.numerator
    b = vi.denominator
    g = lcm // b
    a *= g
    sol.append(int(a))
  sol.append(int(lcm))
  return sol

def identity(n):
  C = [[0  for j in range(n)] for i in range(n)]
  for i in range(n):
    C[i][i] = 1
  return C


def reachable(m):
  n = len(m)
  adj = [[0  for j in range(n)] for i in range(n)]
  
  for i in range(n):
    for j in range(n):
      if m[i][j] > 0:
        adj[i][j] = 1
  vis = [False for i in range(n)]
  q = [0]
  while len(q) > 0:
    u = q[0]
    q = q[1:]
    if vis[u]:
      continue
    vis[u] = True
    for i in range(n):
      if adj[u][i] and not vis[i]:
        q.append(i)
  sol = []
  for i in range(n):
    if vis[i]:
      sol.append(i)
  return sol

def solution(m):
  # Your code here
  n = len(m)
  terminals = []
  for i in range(n):
    s = 's{} = '.format(i)
    S = max(0, sum(m[i]))
    if S == 0:
      m[i][i] = 1
      S = 1
      terminals.append(i)
    for j in range(n):
      m[i][j] = Fraction(m[i][j], S)
      if m[j][i] > 0:
        s += '{}s{} + '.format(m[j][i], j)
    #print(s)
  #display(m)
  v = [[0 for i in range(n)]]
  v[0][0] = 1
  N = int(1e18)
  C = power(m, N)
  v = multp(v, C)
  sol = []
  for i in terminals:
    sol.append(v[0][i].limit_denominator())
  #print('here')
  #print(sol)
  #print(sum(sol))      
  
  sol, lcm = normalize(sol)
  sol.append(lcm)
  return sol

m = [
        [0, 1, 0, 0, 0, 1],
        [4, 0, 0, 3, 2, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]

print(solution(m))
