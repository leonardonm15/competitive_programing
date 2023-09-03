t = int(input())
for _ in range(t):
    n = int(input()) #array length
    a = [int(a) for a in input().split(' ')]
    d = {}
    flag = 0
    for value in a:
        if value in d.keys():
            d[value] += 1
        else:
            d[value] = 1
 
        if d[value] >= 3:
            print(value)
            flag = 1
            break
 
    if flag == 0:
        print('-1')
