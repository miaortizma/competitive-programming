T = int(input())

def odd(x):
  return x & 1

def even(x):
  return not odd(x)

for t in range(T):
  a, b = map(int, input().split())
  s = list(input())
  n = len(s)

  pal = True
  for i in range(n // 2):
    if s[i] == '?' and s[n - 1 - i] != '?':
      s[i] = s[n - 1 - i]
    elif s[i] != '?' and s[n - 1 - i] == '?':
      s[n - 1 - i] = s[i]
    if s[i] != '?' and s[n - 1 - i] != '?' and s[i] != s[n - 1 - i]:
      pal = False

  if not pal:
    print(-1)
    continue

  # odd
  if odd(n):
    if odd(a) and even(b):
      if s[n // 2] == '?':
        s[n // 2] = '0'
        a -= 1
      elif s[n // 2] == '0':
        a -= 1
    elif even(a) and odd(b):
      if s[n // 2] == '?':
        s[n // 2] = '1'
        b -= 1
      elif s[n // 2] == '1':
        b -= 1
  # even
  if even(a) and even(b):
    cnt_0 = 0
    cnt_1 = 0
    for i in range(n // 2):
      if s[i] == '0':
        cnt_0 += 2
      elif s[i] == '1':
        cnt_1 += 2
    if cnt_0 <= a and cnt_1 <= b:
      for i in range(n // 2):
        if s[i] == '?' and cnt_0 < a:
          cnt_0 += 2
          s[i] = '0'
          s[n - 1 - i] = '0'
        if s[i] == '?' and cnt_1 < b:
          cnt_1 += 2
          s[i] = '1'
          s[n - 1 - i] = '1'
  #print(s)
  if cnt_0 == a and cnt_1 == b:
    print(''.join(s))
  else:
    print(-1)
  #print(cnt_0, cnt_1)
  #print(s)
  #print(ans)
