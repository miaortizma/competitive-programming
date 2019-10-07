
N = 100000

with open('in.txt', 'w') as f:
    f.write('1\n')
    f.write('5 '+str(N)+'\n')
    for i in range(N - 1):
        f.write('U 1 10000\n')
    f.write('Q 1 2\n')
    
        
