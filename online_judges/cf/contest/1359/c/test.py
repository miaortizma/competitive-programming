h = 18
c = 13

for t in range(1, 100):
  h_c = t / 2 + t % 2
  c_c = t / 2
  avg = (h * h_c + c * c_c ) / t
  print(t, avg)
    
