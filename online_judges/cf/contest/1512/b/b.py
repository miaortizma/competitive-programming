T = int(input())
for t in range(T):
  n = int(input())
  mat = []
  for i in range(n):
    mat.append(list(input()))
  

  p1 = (-1, -1)
  p2 = (-1, -1)

  for i in range(n):
    for j in range(n):
      if mat[i][j] == '*':
        if p1 == (-1, -1):
          p1 = (i, j)
        else:
          p2 = (i, j)
  
  # same row
  if p1[0] == p2[0]:
    row = p1[0]
    y0 = p1[1]
    y1 = p2[1]
    if row + 1 < n:
      mat[row + 1][y0] = '*'
      mat[row + 1][y1] = '*'
    else:
      mat[row - 1][y0] = '*'
      mat[row - 1][y1] = '*'
  # same column
  elif p1[1] == p2[1]:
    x0 = p1[0]
    x1 = p2[0]
    col = p1[1]
    if col + 1 < n:
      mat[x0][col + 1] = '*'
      mat[x1][col + 1] = '*'
    else:
      mat[x0][col - 1] = '*'
      mat[x1][col - 1] = '*'
  else:
    x0, y0 = p1
    x1, y1 = p2
    mat[x0][y1] = '*'
    mat[x1][y0] = '*'
  for i in range(n):
    print(''.join(mat[i]))


      