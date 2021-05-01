N, D, H = map(int, input().split())


ans = 0
for i in range(N):
    Di, Hi = map(int, input().split())
    m = (H - Hi) / (D - Di)
    b = H - m * D
    ans = max(ans, b)

print(ans)
    
