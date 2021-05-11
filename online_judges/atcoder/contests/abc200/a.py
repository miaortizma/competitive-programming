N = int(input())

C = N // 100
if N % 100 == 0:
    print(C)
else:
    print(C + 1)


