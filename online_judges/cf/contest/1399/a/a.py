import sys
input = sys.stdin.readline
t = int(input())
for ti in range(t):
  n = int(input())
  in = [False] * 100
  arr = list(map(int, input().split()))
  for v in arr:
    in[v] = True
  mi = min(arr)
  ma = max(arr)
  ok = True
  for i in range(mi, ma + 1):
    if not in[i]:
      ok = False
      break
  if ok:
    print('YES')
  else:
    print('NO')
