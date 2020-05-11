for _ in range(int(input())):
    n, k = map(int, input().split())
    p = [0] + list(map(int, input().split()))
    visited = [False] * (n + 1)
    cycles = []
    for i in range(1, n + 1):
        cycle = []
        while not visited[i]:
            visited[i] = True
            cycle += i,
            i = p[i]
        if cycle:
            cycles += cycle,
    ans = []
    tmp = []
    flag = True
    for i in cycles:
        for j in range(1, len(i) - 1, 2):
            ans += [i[0], i[j], i[j + 1]],
        if len(i) % 2 == 0:
            tmp += [i[0], i[-1]],
    if len(tmp) % 2:
        flag = False
    else:
        for i in range(0, len(tmp), 2):
            ans.extend([[tmp[i][0], tmp[i][1], tmp[i + 1][0]], [tmp[i + 1][0], tmp[i][0], tmp[i + 1][1]]])
    if flag and len(ans) <= k:
        print(len(ans))
        for i in ans:
            print(*i)
    else:
        print(-1)
