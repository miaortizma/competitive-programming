def dist(X, m):
  S = 0
  for x in X:
    S += abs(x - m)
  return S

T = int(input())

for ti in range(T):
  N, M, F = map(int, input().split())
  X = []
  Y = []
  for fi in range(F):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
  X = sorted(X)
  Y = sorted(Y)
  F = 2
  if F & 1:
    xx = str(X[F // 2])
    yy = str(Y[F // 2])
    print('(Street: ' + xx  + ', Avenue: ' + yy + ')')
  else:
    a = F // 2
    b = (F // 2) - 1
    A = dist(X, X[a]) + dist(Y, Y[a])
    B = dist(X, X[b]) + dist(Y, Y[b])
    print(A, B)
    if A < B:
      xx = str(X[a])
      yy = str(Y[a])
      print('(Street: ' + xx  + ', Avenue: ' + yy + ')')
    else:
      xx = str(X[b])
      yy = str(Y[b])
      print('(Street: ' + xx  + ', Avenue: ' + yy + ')')
