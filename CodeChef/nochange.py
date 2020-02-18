#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb 18 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    N, P = map(int, input().split())
    D = list(map(int, input().split()))
    L = [0] * N
    F = 1
    for I in range(N - 1, -1, -1):
        if P % D[I] != 0:
            L[I] = P // D[I] + 1
            print('YES', ' '.join(map(str, L)))
            F = 0
            break
    if F == 1:
        K = 0
        X = 0
        while X <= P and K < N:
            A = 0
            L = [0] * N
            for I in range(K, N):
                if 1 < D[I] < P:
                    L[I] = P // D[I] - 1
                    X += L[I] * D[I]
                    A = D[I]
                    break
            for I in range(N):
                if X + D[I] > P > D[I] > 1 and D[I] % A != 0:
                    L[I] += 1
                    X += D[I]
                    break
            for I in range(N):
                if L[I] > 0:
                    Q = (X - P) // D[I]
                    L[I] -= Q
                    X -= Q * D[I]
                    break
            if X > P:
                print('YES', ' '.join(map(str, L)))
                break
            else:
                K += 1
                X = 0
        else:
            print('NO')