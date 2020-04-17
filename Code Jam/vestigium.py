for _ in range(int(input())):
    N = int(input())
    M = [list(map(int, input().split())) for I in range(N)]
    T = sum(M[I][I] for I in range(N))
    R = 0
    C = 0
    for I in range(N):
        if len(set(M[I])) != N:
            R+=1
    for I in range(N):
        CI = set()
        for J in range(N):
            CI.add(M[J][I])
        if len(CI) != N:
            C+=1
    print('Case #{}: {} {} {}'.format(_+1, T, R, C))