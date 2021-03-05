from fractions import Fraction

def gcd(a, b):
  if a == 0:
    return b
  else:
    return gcd(b % a, a)
  
def subsum(v, subset):
  S = 0
  for i in subset:
    S += v[i]
  return S

def normalize(v):
  lcm = 1
  denominator = 1
  for vi in v:
    a = vi.numerator
    b = vi.denominator
    if vi != 0:
      g = gcd(denominator, b)
      lcm = (denominator * b) // g
  sol = []
  for vi in v:
    a = vi.numerator
    b = vi.denominator
    g = lcm // b
    a *= g
    sol.append(a)
  sol.append(lcm)
  
  return sol

def solution(m):
  n = len(m)
  nonterminals = []
  terminals = []
  for i in range(n):
    S = sum(m[i])
    if S == 0:
      m[i][i] = 1
      S = 1
      terminals.append(i)
    else:
      nonterminals.append(i)
  
  state = [Fraction(0) for i in range(n)]
  state[0] = 1
  """
  print(terminals)
  for line in m:
    for f in line:
      print(f, end='\t')
    print()
  """
  
  for i in range(1000):
    nstate = [Fraction(0) for i in range(n)]
    for u in range(n):
      for v in range(n):
        if m[u][v] > 0:
          nstate[v] += state[u] * m[u][v]
    state = nstate
  sol = []
  for i in terminals:
    v = state[i].limit_denominator()
    sol.append(v)
  return normalize(sol)      
      


if __name__ == '__main__':
  #m = [[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0,0], [0, 0, 0, 0, 0]]
  m = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
  
  a = solution(m)
  print(a)
    
      

  
