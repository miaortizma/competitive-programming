def bits(i):
  j = 0
  ret = []
  while(i):
    if i & 1:
      ret.append(j)
    j += 1
    i >>= 1
  return ret

def get(arr, k):
  ret = []
  n = len(arr)
  for i in range(1 << n):
    b = bits(i)
    if len(b) == k:
      ret.append(sum([arr[j] for j in b]))
  ret = sorted(ret)
  return ret

def advantage(a, b, k):
  w, l = 0, 0
  for x in get(a, k):
    for y in get(b, k):
      print(x, y)
      if x > y:
        w += 1
      elif y > x:
        l += 1
  print(w, l)
  return w > l
def find():  
  for i in range(1, 10):
    for j in range(i, 10):
      for k in range(j, 10):
        for x in range(1, 10):
          for y in range(x, 10):
            for z in range(y, 10):
              a = [i, j, k]
              b = [x, y, z]
              if advantage(a, b, 1) and advantage(b, a, 2) and advantage(a, b, 3):
                print(a)
                print(b)
                return

a = [1, 5, 5]
b = [3, 3, 4]
print(3)
for x in a:
  print(x, end=' ')
print()
print(3)
for x in b:
  print(x, end=' ')
  
#aa = advantage(a, b, 1)
#print(aa)
#aa = advantage(b, a, 2)
#print(aa)
#aa = advantage(a, b, 3)
#print(aa)
#find()
