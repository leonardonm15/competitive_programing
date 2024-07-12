for tt in range(int(input())):
    n = int(input())
    nr = str(n)
    r = []
    for a in range(10001):
        if a == 0:
            continue
        nnr = int(nr * a)
        resp = n * a
        counter = 0
        while nnr > 0:
            if nnr == resp - counter and counter > 0 and counter < resp and counter < 10000:
                r.append(a, counter)
            nnr /= 10
            counter += 1
    
    print(len(r) / 2)
    for i in range(len(r)):
        if (i % 2 == 1):
            print(r[i - 1] + " " + r[i])


