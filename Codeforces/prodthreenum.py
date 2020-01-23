#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 23 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    N = int(input())
    D = set()
    for I in range(2, int(N ** 0.5) + 1):
        if N % I == 0:
            D.update([I, N//I])
    D = sorted(list(D))
    F = 0
    if len(D) < 3:
        F = 1
        print('NO')
    else:
        for I in range(len(D)):
            for J in range(len(D)):
                if I != J:
                    X = N / D[I] / D[J]
                    if X != D[I] and X != D[J] and X > 1 and X % 1 == 0:
                        F = 1
                        print('YES')
                        print(D[I], D[J], int(X))
                        break
            if F == 1:
                break
    if F == 0:
        print('NO')
