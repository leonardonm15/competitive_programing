t = int(input())
for _ in range(t):
    n = int(input())
    s = str(input()) # final string
    s = s.split('W')
    flag = 0
    for lista in s:
        
        if lista == '':
            continue
        
        if lista == 'R' * len(lista) or lista == 'B' * len(lista):
            print('NO')
            flag = 1    
            break
        
    if flag == 0:
        print('YES')
