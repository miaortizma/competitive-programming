a, b, c = map(int, input().split())

left = a * a + b * b

if left < c * c:
    print('Yes')
else:
    print('No')
