for _ in range(int(input())):
    N, M, K = map(int, input().split())
    A = [0] * N
    for I in range(N):
        A[I] = list(map(int, input().split()))
    I = 0
    C = [0] * K
    ANS = [1] * N
    while I < N:
        MIN = min(C)
        F = {}
        for J in range(K):
            if C[J] <= MIN + 2:
                try:
                    F[A[I][J]] += 1
                except:
                    F[A[I][J]] = 1
        ANS[I] = max(F, key=F.get)
        for J in range(K):
            if ANS[I] == A[I][J]:
                C[J] += 1
        I -= 1
    print(' '.join(map(str, ANS)))