#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 14 12:00:00 2020

@author: divyanshvinayak
"""

T = int(input())
for I in range(T):
    N, M = map(int, input().split())
    P = N * M
    A = list(range(N))
    for J in range(N):
        A[J] = list(map(int, input().split()))
    for X in range(1, N - 1):
        for Y in range(1, M - 1):
            K = 1
            while X - K > -1 and X + K < N and Y - K > -1 and Y + K < M:
                if A[X - K][Y] == A[X + K][Y] and A[X][Y - K] == A[X][Y + K]:
                    P += 1
                    K += 1
                else:
                    break
    print(P)
