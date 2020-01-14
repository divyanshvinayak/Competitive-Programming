#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 14 12:00:00 2020

@author: divyanshvinayak
"""

N, Q = map(int, input().split())
A = list(map(int, input().split()))
MAX = [0] * N
MIN = [0] * N
F = 0
if A[1] < A[0]:
    F = 1
for I in range(1, N):
    if A[I] > A[I - 1]:
        if F == 0:
            MAX[I] = MAX[I - 1] + 1
            F = 1
        elif F == 1:
            MAX[I] = MAX[I - 1]
        MIN[I] = MIN[I - 1]
    else:
        if F == 1:
            MIN[I] = MIN[I - 1] + 1
            F = 0
        elif F == 0:
            MIN[I] = MIN[I - 1]
        MAX[I] = MAX[I - 1]
for I in range(Q):
    L, R = map(int, input().split())
    X = MAX[R - 1] - MAX[L - 1]
    Y = MIN[R - 1] - MIN[L - 1]
    if MAX[L - 1] == MAX[L] and A[L - 1] < A[L]:
        X += 1
    elif MIN[L - 1] == MIN[L] and A[L - 1] > A[L]:
        Y += 1
    if X == Y and R - L > 1:
        print('YES')
    else:
        print('NO')
