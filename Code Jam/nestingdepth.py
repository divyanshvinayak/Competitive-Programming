for _ in range(int(input())):
    S = input()
    D = 0
    Z = ''
    for C in S:
        X = int(C) - D
        if X > 0:
            Z+='('*X+C
            D = int(C)
        elif X < 0:
            Z+=')'*(-X)+C
            D = int(C)
        else:
            Z+=C
    Z+=')'*D
    print('Case #{}: {}'.format(_+1, Z))