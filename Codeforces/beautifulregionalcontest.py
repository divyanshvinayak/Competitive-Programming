#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 12:00:00 2019

@author: divyanshvinayak
"""

T = int(input())
for X in range(T):
    N = int(input())
    P = list(map(int, input().split()))
    D = {}
    G = S = B = A = 0
    for I in range(len(P)):
        if P[I] in D:
            D[P[I]]+=1
        else:
            D[P[I]] = 1
            if 0 < I < N//2 + 1:
                A+=D[P[I-1]]
    Z = list(D.keys())
    G = D[Z[0]]
    I = 1
    while S <= G and I < len(Z) - 1:
        S+=D[Z[I]]
        I+=1
    B = A - G - S
    if 0 < G < S and G < B:
        print(G, S, B)
    else:
        print(0, 0, 0)
