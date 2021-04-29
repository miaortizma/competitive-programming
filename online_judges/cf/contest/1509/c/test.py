with open('in7.txt', 'w') as f:
    f.write('2000\n')
    s = '1 '
    for i in range(1999):
        s += ' 1000000000'
    f.write(s)

a = [3, 3, 3, 2, 1, 1, 4, 5]

cur = 0
mn = a[0]
mx = a[0]

for x in a:
    mn = min(mn, x)
    mx = max(mx, x)
    cur += mx - mn

print(cur)
