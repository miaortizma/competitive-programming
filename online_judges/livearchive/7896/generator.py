import random

def gen(n, i):
    x = random.randint(1, n)
    while x == i:
        x = random.randint(1, n)
    y = random.randint(1, n)
    while y == i or y == x:
        y = random.randint(1, n)
    return x, y


n = 5
with open('in4.txt', 'w') as f:
    f.write(str(n) + '\n')
    for i in range(1, n + 1):
        a, b = gen(n, i)
        s = '{} {}\n'.format(a, b)
        f.write(s)

for i in range(100):
    print('.' * 100)
