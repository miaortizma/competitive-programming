N = int(input())
S = input()
Q = int(input())

le = list(S[:N])
ri = list(S[N:])


for q in range(Q):
    T, A, B = map(int, input().split())
    
    #print(le, ri)
    if T == 1:
        if A <= N and B <= N:
            A = A - 1
            B = B - 1
            le[A], le[B] = le[B], le[A]
        elif A > N and B > N:
            A = A - N - 1
            B = B - N - 1
            ri[A], ri[B] = ri[B], ri[A]
        elif A <= N and B > N:
            A = A - 1
            B = B - N - 1
            le[A], ri[B] = ri[B], le[A]
        elif A > N and B <= N:
            A = A - N - 1
            B = B - 1
            ri[A], le[B] = le[B], ri[A]
    else:
        le, ri = ri, le

ans = ''.join(le) + ''.join(ri)

print(ans)
    
