#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 12:00:00 2019

@author: divyanshvinayak
"""

T = int(input())
for X in range(T):
    N = int(input())
    S = input()
    D = {}
    for Y in range(N):
        if S[Y] in D:
            D[S[Y]].append(Y)
        else:
            D[S[Y]] = [Y]
    M = N
    for I in D:
        for J in range(len(D[I])-1):
            if D[I][J+1] - D[I][J] < M:
                M = D[I][J+1] - D[I][J]
    print(N-M)
