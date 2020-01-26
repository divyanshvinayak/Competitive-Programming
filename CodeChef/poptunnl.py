#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 26 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    N, K = map(int, input().split())
    S = [input() for _ in range(N)]
    J = 0
    Q = {0}
    V = [True] + [False] * (N - 1)
    while Q:
        if N - 1 in Q:
            print(J)
            break
        W = set()
        J += 1
        for P in Q:
            for I in range(max(0, P - K), min(P + K + 1, N)):
                if not V[I]:
                    if S[P][I] == '1':
                        W.add(I)
                        V[I] = True
        Q = W
    else:
        print(-1)
