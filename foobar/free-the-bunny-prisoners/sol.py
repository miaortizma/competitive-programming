def bits(i):
  I = 0
  ret = []
  while i:
    if i & 1:
      ret.append(I)
    I += 1
    i >>= 1
  return ret

def all_keys(sol, inds, num_keys):
  keys = [False for i in range(num_keys)]
  for i in inds:
    for j in sol[i]:
      keys[j] |= True
  return all(keys)


def next_combination(a, n):
  k = len(a)
  for i in range(k - 1, -1, -1):
    if a[i] < n - k + i:
      a[i] += 1
      for j in range(i + 1, k):
        a[j] = a[j - 1] + 1
      return True
  return False

def is_valid(sol, num_required):
  """
  O((n choose num_required) * num_required * num_keys)
  """
  num_keys = max([max(i) for i in sol]) + 1
  num_buns = len(sol)
  f_all_keys = lambda b : all_keys(sol, b, num_keys)

  #bunnies = list(range(num_required))
  #while next_combination(bunnies, num_buns)
  
  for i in range(1 << num_buns):
    b = bits(i)
    if len(b) < num_required:
      if f_all_keys(b):
        print('not valid with num_required: {}'.format(num_required))
        print('found countercase: {}, {}'.format(len(b), b))
        return False
    if len(b) == num_required:
      if not f_all_keys(b):
        return False
  print('is valid with num_required: {}'.format(num_required))
  return True

def print_sol(ans):
  num_keys = max([max(i) for i in ans]) + 1
  print(' \t', end='')
  for i in range(0, num_keys):
    print(str(i) + '\t', end='')
  print()
  for i, bun in enumerate(ans):
    keys = [False] * num_keys
    print(str(i) + '\t', end='')
    for i in bun:
      keys[i] = True
    for i in range(num_keys):
      if keys[i]:
        print('X\t', end='')
      else:
        print(' \t', end='')
    print()
  
def solution(num_buns, num_required):
  if num_required == 0:
    return [[] for i in range(num_buns)]
  if num_required == 1:
    return [[0] for i in range(num_buns)]
  if num_buns == num_required:
    return [[i] for i in range(num_buns)]
  if num_required == 2:
    keys = list(range(num_buns))
    sol = []
    for i in range(num_buns):
      j = num_buns - 1 - i
      sol.append(keys[:j] + keys[j + 1:])
    return sol
  left = solution(num_buns - 1, num_required)
  right = solution(num_buns - 1, num_required - 1)
  num_keys_left = max([max(i) for i in left]) + 1
  keys_per_bun = len(left[0]) + len(right[0])
  sol = []
  sol.append(list(range(keys_per_bun)))
  for i in range(num_buns - 1):
    left_i = left[i]
    right_i = right[i]
    right_i = [ j + num_keys_left for j in right_i]
    sol.append(left_i + right_i)
  return sol
    
found = False
tried = 0

def brute_aux(buns, i, num_buns, num_required, num_keys):
  global found, tried
  if found:
    return
  buns[i] = buns[i - 1].copy()
  if i == num_buns - 1:
    while next_combination(buns[i], num_keys):
      tried += 1
      if tried % 100000 == 0:
        print('tried: ', tried)
        print_sol(buns)
      if is_valid(buns, num_required):
        found = True
        break
    return
  while next_combination(buns[i], num_keys):
    brute_aux(buns, i + 1, num_buns, num_required, num_keys)
    if found:
      return

def brute_try(num_buns, num_required, num_keys, keys_per_bun):
  global found
  buns = [[]] * num_buns
  buns[0] = list(range(keys_per_bun))
  
  
  brute_aux(buns, 1, num_buns, num_required, num_keys)
  if found:
    return buns
  
  return False

#ans = brute_try(num_buns=6, num_required=3, num_keys=15, keys_per_bun=10)
#if found:
  #print_sol(ans)
#else:
  #print('sol not found')
"""
for i in range(1, 10):
  for j in range(i + 1):
    sol = solution(i, j)
    if i < 9 and j > 0:
      print('num_buns: {}, num_required: {}'.format(i, j))
      print_sol(sol)

assert(
  solution(3, 1) == [[0], [0], [0]]
)

assert(
  solution(2, 2) == [[0], [1]]
)

assert(
  solution(5, 4) == [
    [0, 1, 2, 3],
    [0, 4, 5, 6],
    [1, 4, 7, 8],
    [2, 5, 7, 9],
    [3, 6, 8, 9]
  ]
)

assert(
  solution(3, 2) == [
    [0, 1],
    [0, 2],
    [1, 2]
  ]
)

assert (
  solution(6, 3) == [
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
    [0, 1, 2, 3, 4, 5, 10, 11, 12, 13],
    [0, 1, 2, 6, 7, 8, 10, 11, 12, 14],
    [0, 3, 4, 6, 7, 9, 10, 11, 13, 14],
    [1, 3, 5, 6, 8, 9, 10, 12, 13, 14],
    [2, 4, 5, 7, 8, 9, 11, 12, 13, 14]
  ]
)
"""
