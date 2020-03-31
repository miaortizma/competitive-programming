import random

B = int(1)

def gen(c=1):
  n = random.randint(0, B // c)
  m = random.randint(0, B // c)
  a = random.randint(0, B // c)
  k = random.randint(0, B // c)
  return n, m, a, k

def solve(case):
  n, m, a, k = case
  if (n - k > 0 and n - k % a == 0):
    return n
  else:
    if (n < k):
      n, m, a, k = k, a, m, n
    for i in range(1, int(1e6)):
      if ((n + m * i - k) % (a) == 0):
        return n + m * i
  return -1

case = gen()
n, m, a, k = case
print(n, m, a, k)
print(solve(case))

cases = [(5, 4, 3, 3),
         (3, 5, 2, 2),
         (3, 3, 5, 4), (3, 3, 4, 5), (5, 12, 30, 11),
         (1, 2, 4, 5), (10, 20, 355, 202)]

#for case in cases:
#  print(solve(case))


