import sys
input = sys.stdin.readline
n = int(input())

arr = list(map(int, input().split()))

se = set()
for i in range(n):
  if len(se) <= 3:
    se.add(arr[i])

if len(se) <= 2:
  print('YES')
elif len(se) == 3:
  arr = list(se)
  arr = sorted(arr)
  if abs(arr[0] - arr[1]) == abs(arr[1] - arr[2]):
    print('YES')
  else:
    print('NO')
else:
  print('NO')
  
