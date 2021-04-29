def cnt(x):
    ret = 0
    while(x):
        ret += 1
        x //= 10
    return ret

def step(x):
    c = x // 2050
    power = cnt(c) - 1
    d = (10 ** power) * 2050
    return (x - d)

def solve(x):
    if x % 2050 != 0:
        return -1
    ans = 0
    while (x):
        ans += 1
        #print(x)
        x = step(x)
    return ans
    

T = int(input())
for i in range(T):
    x = int(input())
    print(solve(x))

