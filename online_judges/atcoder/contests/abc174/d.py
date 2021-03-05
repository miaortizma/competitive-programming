import sys
input = sys.stdin.readline
n = int(input())
s = input()
ans = 0
r = [0] * n
w = [0] * n
for i in range(n):
  if s[i] == 'W':
    w[i] += 1
  else:
    r[i] += 1
for i in range(1, n):
  w[i] += w[i - 1]
  r[i] += r[i - 1]
rn = r[n - 1]
ans = n
if rn == 0:
  ans = 0
for i in range(n):
  c = (i + 1)
  ri = r[i]
  left = rn - ri
  need = c - ri
  ans = min(ans, max(left, need))  

print(ans)
