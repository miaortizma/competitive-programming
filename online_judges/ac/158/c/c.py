n = int(input())

pwd = '/'

for i in range(n):
  in_ = input().split()
  if(in_[0] == 'pwd'):
    print(pwd)
  else:
    cd = in_[1]
    if(cd[0] == '/'):
      pwd = '/'
      cd = cd[1:]

    pwda = pwd[:-1].split('/')
    
    cd = cd.split('/')
    for move in cd:
      if(move == '..'):
        pwda = pwda[:-1]
      else:
        pwda = pwda + [move]
    # print(cd, pwda)
    pwd = '/'.join(pwda) + '/'

