N = 10

A = []

for i in range(N):
  row = []
  for j in range(N):
    l = i + j
    l_start = (l * (l + 1)) // 2
    val = l_start + i + 1
    #A[i][j] = val + i + 1
    #print(i, j)
    print(val, end=' ')
    row.append(val)
  print()
  A.append(row)

sums = [[[] for j in range(N)] for i in range(N)]
for i in range(N):
  sums[0][i] = [A[0][i]]
  sums[i][0] = [A[i][0]]
for i in range(1, N):
  for j in range(1, N):
    cur = []
    left = sums[i][j - 1]
    up = sums[i - 1][j]
    for x in left:
      cur.append(x + A[i][j])
    for x in up:
      cur.append(x + A[i][j])
    cur = set(cur)
    sums[i][j] = cur
    print(i * j + 1, end=' ')
  print()
