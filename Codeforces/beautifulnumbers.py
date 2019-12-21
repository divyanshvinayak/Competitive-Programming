#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 12:00:00 2019

@author: divyanshvinayak
"""

T = int(input())
for I in range(T):
    N = int(input())
    P = list(map(int, input().split()))
    D = ['0' for x in range(N)]
    for J in range(N):
        C = 1
        MIN = J-P[J]
        MAX = J+P[J]
        if MIN<-1:
            MIN = -1
        if MAX>N:
            MAX = N
        for K in range(J-1, MIN, -1):
            if P[K] < P[J]:
                C+=1
            else:
                break
        for K in range(J+1, MAX):
            if P[K] < P[J]:
                C += 1
            else:
                break
        if C == P[J]:
            D[P[J]-1] = '1'
    print(''.join(D))
