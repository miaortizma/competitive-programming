S = input()

N = len(S)
P = 'ZONe'

ans = 0
for i in range(N - len(P) + 1):
    ok = True
    #print(i)
    for j in range(len(P)):
        
        #print(S[i + j], P[j])
        if S[i + j] != P[j]:
            ok = False
            break
    if ok:
        ans += 1
print(ans)
