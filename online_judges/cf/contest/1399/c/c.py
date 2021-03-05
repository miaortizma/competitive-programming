import sys
input = sys.stdin.readline

t = int(input())
for ti in range(t):
    n = int(input())
    count = [0] * 51
    arr = list(map(int, input().split()))
    for i in arr:
      count[i] += 1
    ans = 0
    for i in range(2, n + 1):
      cur = 0
      for j in range(1, (i + 1) // 2 + 1):
        if i - j != j:
          tms = min(count[j], count[i - j])
        else:
          tms = count[j] // 2
        cur += tms
      ans = max(ans, cur)
    print(ans)





        
