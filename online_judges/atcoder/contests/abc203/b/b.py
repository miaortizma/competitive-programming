N, K = map(int, input().split())

S = 0

for i in range(1, N + 1):
    for j in range(1, K + 1):
        S += int(f'{i}0{j}')

print(S)
