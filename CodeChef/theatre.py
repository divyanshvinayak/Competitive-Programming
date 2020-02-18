#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 18 12:00:00 2020

@author: divyanshvinayak
"""

from itertools import permutations
Z = []
for _ in range(int(input())):
    N = int(input())
    D = [[0 for x in range(4)] for y in range(4)]
    for I in range(N):
        M, T = input().split()
        D[ord(M) - 65][int(T) % 12 // 3] += 1
    L = list(permutations([0, 1, 2, 3], 4))
    P = []
    for J in range(24):
        C = 0
        X = sorted([D[0][L[J][0]], D[1][L[J][1]], D[2][L[J][2]], D[3][L[J][3]]])
        for K in range(4):
            if X[K] == 0:
                C -= 100
            else:
                C += X[K] * 25 * (K + 1)
        P += C,
    Z += max(P),
print(*Z, sep='\n')
print(sum(Z))