import sys
input = sys.stdin.readline
K = int(input())
seven = 7 % K
c = 0
p = 1 % K
found = False
for i in range(K + 1):
  c = (c + p % K) % K
  if ((seven * c) % K == 0):
    found = True
    print(i + 1)
    break
  p = (p * (10 % K) ) % K
  #print(i, p)

if not found:
  print(-1)
