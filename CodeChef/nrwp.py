from itertools import product

for _ in range(int(input())):
    H, W, N = map(int, input().split())
    h = [list(map(int, input().split())) for i in range(H)]
    y = [0] * N
    x = [0] * N
    p = [0] * N
    yx = [[]] * N
    links = [[]] * N
    values = [0] * N
    for i in range(N):
        y[i], x[i], p[i] = map(int, input().split())
        yx[i] = [y[i], x[i]]
        values[i] = h[y[i] - 1][x[i] - 1]
        links[i] = []
    for i in range(N):
        try:
            links[i] += yx.index([y[i] + 1, x[i]]),
        except:
            pass
        try:
            links[i] += yx.index([y[i], x[i] + 1]),
        except:
            pass
    signs = list(product([1, -1], repeat=N))
    ans = 0
    z = signs[0]
    for sign in signs:
        total = 0
        for j in range(N):
            for k in links[j]:
                total += p[j] * sign[j] * p[k] * sign[k]
            total += p[j] * sign[j] * values[j]
        if total > ans:
            ans = total
            z = sign
    print(ans)
    print(*z)
