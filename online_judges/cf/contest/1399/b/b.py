import sys
input = sys.stdin.readline


t = int(input())

for ti in range(t):
  n = int(input())
  a = list(map(int, input().split())
  b = list(map(int, input().split())
  mia = min(a)
  mib = min(b)
  ans = 0
  for i in range(n):
    da = a[i] - mia
    db = b[i] - mib
    both = min(da, db)
    ans += (da - both) + (db - both)
  print(ans)



