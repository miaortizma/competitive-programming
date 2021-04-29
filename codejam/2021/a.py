def digits(x):
  l = []
  while x:
    l.append(x % 10)
    x = x // 10
  return l[::-1]

def pad(x, size):
  while len(x) < size:
    x = [0] + x
  return x

def toint(digits):
  return int(''.join(map(str, digits)))

def solve(a, b):
  if a < b:
    return b, 0

  d_a = digits(a)
  d_b = digits(b)

  ops = 0

  len_b = len(d_b)

  while len(d_b) < len(d_a):
    ops += 1
    d_b.append(0)

  greater = toint(d_b[:len_b]) > toint(d_a[:len_b])
  
  if greater:
    return toint(d_b), ops

  prefix_equal = d_a[:len_b] == d_b[:len_b]
  
  if prefix_equal:
    all_9 = True
    for i in range(len_b, len(d_a)):
      if d_a[i] != 9:
        all_9 = False
    #print(a, b)
    #print(d_a, d_b)

    if not all_9:
      sufix_len = len(d_a) - len_b
      sufix = pad(digits(toint(d_a[len_b:]) + 1), sufix_len)
      greater = True
      d_b[len_b:] = sufix

  if greater:
    return toint(d_b), ops

  d_b.append(0)

  return toint(d_b), ops + 1
  


T = int(input())

for t in range(T):
    n = int(input())
    arr = list(map(int, input().split()))
    ops = 0
    for i in range(n - 1):
      sol, ops_i = solve(arr[i], arr[i + 1])
      ops += ops_i
      arr[i + 1] = sol
    #print(arr)
    print(f'Case #{t + 1}: {ops}')

