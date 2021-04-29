T = int(input())

for t in range(T):
  n = int(input())
  arr = list(map(int, input().split()))
  mp = {}
  st = set()
  for i in range(n):
    x = arr[i]
    cnt = mp.get(x, 0)
    mp[x] = cnt + 1
    st.add(x)
  single = 0
  for x in st:
    if mp[x] == 1:
      single = x
  for i in range(n):
    if arr[i] == single:
      print(i + 1)
