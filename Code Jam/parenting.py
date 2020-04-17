for _ in range(int(input())):
    N = int(input())
    SE = [0] * N
    for I in range(N):
        SE[I] = list(map(int, input().split()))+[I]
    SE.sort(key=lambda x: x[0])
    Z = ['C'] * N
    C = SE[0][1]
    J = 0
    F = 1
    for I in range(1, N):
        if C <= SE[I][0]:
            C=SE[I][1]
        elif J <= SE[I][0]:
            Z[SE[I][2]]='J'
            J=SE[I][1]
        else:
            print('Case #{}: {}'.format(_+1, 'IMPOSSIBLE'))
            F = 0
            break
    if F:
        print('Case #{}: {}'.format(_+1, ''.join(Z)))