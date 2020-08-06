'''
for n in range(1, 201):
  for m in range(1, 201):
    a = n * m + n + m - 3
    b = 2 * n * m
    if (b < a):
      print(n, m)
'''

n, m, k = map(int, input().split())
steps = n * m + n + m - 3
print(steps)
for i in range(n - 1):
  print('U', end='')
for i in range(m - 1):
  print('L', end='')
for i in range(n):
  for j in range(m - 1):
    if i & 1:
      print('L', end='')
    else:
      print('R', end='')
  if i != n - 1:
    print('D', end='')
  
