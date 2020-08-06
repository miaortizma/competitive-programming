m = 1099511627776
s0 = 1611516670

def nes(s):
  return (s + (s >> 20) + 12345) % m

def nes2(s):
  return (s + 12345) % 2
  

n = int(input())

s1 = s0
string = ''

ones = 0
last_sequence = 0

for i in range(1, n + 1):
  m2 = s0 % 2
  string += str(m2)
  if m2 == 1:
    ones += 1
  else:
    if (ones > 1):
      print('sequence of ones', ones)
      print('ending at {}', i - 1)
      print('diff with last sequence end:', i - 1 - last_sequence)
      last_sequence = i - 1
    ones = 0
  if i % 50 == 0:
    #print(string)
    string = ''
  s0 = nes(s0)
  
  
  



