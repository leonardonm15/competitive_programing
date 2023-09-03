t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(a) for a in input().split(' ')]
    a = [num%2 for num in a]
    if a[::2] == [0 for _ in range(len(a[::2]))] or a[::2] == [1 for _ in range(len(a[::2]))]:
        if a[1::2] == [0 for _ in range(len(a[1::2]))] or a[1::2] == [1 for _ in range(len(a[1::2]))]:
            print('YES')
            continue
    print('NO')
