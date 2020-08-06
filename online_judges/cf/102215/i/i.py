n, a = map(int, input().split())
# do full movements first
def solve(n, a):
  full_rows = n // a
  full_vertical_movements = (full_rows - 1) * a
  full_horizontal_movements = full_rows * (n - a)
  ans = full_vertical_movements + full_horizontal_movements
  # now for non complete rows (at most one)
  m = n % a
  if m != 0:
    vertical_movements = m
    horizontal_movements = n - a
    ans += vertical_movements + horizontal_movements
  print(ans)

solve(n, a)
  
#print(3 * (n - a))
#c = 100
#for i in range(c):
  #a, b = c, c - i
  #print(a, b, a - b)
  #solve(a, b)
  #print(3 * (a - b))

