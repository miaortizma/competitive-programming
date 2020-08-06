p, n = map(int, input().split())
s = set()
for i in range(n + 1):
  pos = (i * (i + 1)) // 2
  s.add(pos % p)
#print(s)
print(len(s))
