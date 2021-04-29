def nextJ(J, N):
  M = len(J)
  J[0] = J[0] + 1
  for i in range(M):
    if J[i] == N[i] + 1:
      J[i] = 0
      J[i + 1] = J[i + 1] + 1
  return J

def value(P, J, N):
  M = len(P)
  left = 0
  right = 1
  for i in range(M):
    left += P[i] * J[i]
    right = right * (P[i] ** (N[i] - J[i]))
  if left == right:
    return left
  else:
    return 0

T = int(input())
for t in range(T):
  M = int(input())

  P = [0] * M
  N = [0] * M
  
  for i in range(M):
    p, n = map(int, input().split())
    P[i] = p
    N[i] = n

  J = [0] * M

  combs = 1
  for i in range(M):
    combs *= (N[i] + 1)

  best = value(P, J, N)

  for i in range(combs - 1):
    best = max(best, value(P, J, N))
    J = nextJ(J, N)
  
  print(f'Case #{t + 1}: {best}')

  

