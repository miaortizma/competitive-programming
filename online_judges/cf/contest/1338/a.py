import sys
input = sys.stdin.readline


def bitcount(x):
  ans = 0
  while x:
    ans += 1
    x >>= 1
  return ans


def solve():
  T = int(input())
  for t in range(T):
    n = int(input())

    arr = list(map(int, input().split()))
    ans = 0

    for i in range(1, n):
      a = arr[i - 1]
      b = arr[i]
      if b < a:
        x = a - b
        c = bitcount(x)
        ans = max(ans, c)
        arr[i] = a
    
    print(ans)

solve()
