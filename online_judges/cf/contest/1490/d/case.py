with open('in3.txt', 'w') as f:
  f.write('1\n')
  for i in range(1):
    s = ''
    f.write('100\n')
    for j in range(100):
      s += str(j + 1) + ' '
    s += '\n'
    f.write(s)
