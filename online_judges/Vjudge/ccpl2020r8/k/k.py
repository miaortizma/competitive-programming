import sys
input = sys.stdin.readline

T = int(input())

def palindrome(num):
  a = str(num)
  n = len(a)
  for i in range(n):
    if a[i] != a[n - 1 - i]:
      return False
  return True

for ti in range(T):
  num = int(input())
  cnt = 0
  while not palindrome(num):
    a = str(num)[::-1]
    b = int(a)
    num = num + b
    cnt += 1
  print(cnt, num)

