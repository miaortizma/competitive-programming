import sys
import math

input = sys.stdin.readline

def can(arr, m, K):
  need = 0
  for x in arr:
    if x > m:
      need += int(x // m)
  return need <= K

N, K = map(int, input().split())
arr = list(map(int, input().split()))

lo = 1
hi = int(1e9) + 1

while (lo < hi):
  m = int((lo + hi) // 2)
  if (can(arr, m, K)):
    hi = m
  else:
    lo = m + 1
print(lo)
