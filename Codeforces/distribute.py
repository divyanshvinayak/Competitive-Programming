T = int(input())
for I in range(T):
    L = list(map(int, input().split()))
    L.sort()
    D = 0
    if L[2] >= L[0] + L[1]:
        D = L[0] + L[1]
    else:
        D += L[1] - L[0]
        L[2] -= L[1] - L[0]
        L[1] = L[0]
        D += (L[0]+L[1]+L[2])//2
    print(D)
