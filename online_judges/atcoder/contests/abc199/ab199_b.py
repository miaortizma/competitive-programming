N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))


L = A[0]
R = B[0]
for i in range(N):
    L = max(L, A[i])
    R = min(R, B[i])

if (L <= R):
    print(R - L + 1)
else:
    print(0)
