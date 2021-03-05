import sys
input = sys.stdin.readline

name = input().strip()
n = int(input())

points = {
  "posted": 15,
  "commented": 10,
  "likes": 5,
}

priority = {
}

for i in range(n):
  line = input().split()
  X = line[0]
  Y = line[-2][:-2]
  plus = points[line[1]]
  
  if X == name:
    Y_priority = priority.get(Y, 0)
    priority[Y] = Y_priority + plus
  elif Y == name:
    X_priority = priority.get(X, 0)
    priority[X] = X_priority + plus
  else:
    X_priority = priority.get(X, 0)
    Y_priority = priority.get(Y, 0)
    priority[X] = X_priority
    priority[Y] = Y_priority

L = []
for x in priority:
  L.append((-priority[x], x))

L = sorted(L)
#print(L)
for x, name in L:
  print(name)

"""
aba
3
likes likes posted's post
aba commented b's post
aba commented a's post
"""
