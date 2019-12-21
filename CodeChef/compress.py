#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 12:00:00 2019

@author: divyanshvinayak
"""

T = int(input())
for i in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    S = ''
    F = 0
    L = 0
    for j in range(N - 1):
        if A[j + 1] == A[j] + 1 and F == 0:
            S += str(A[j])
            F = 1
            L = 1
        elif A[j + 1] != A[j] + 1 and F == 0:
            L = 1
            S += str(A[j]) + ','
        elif A[j + 1] == A[j] + 1 and F == 1:
            L += 1
        elif A[j + 1] != A[j] + 1 and F == 1:
            F = 0
            L += 1
            if L > 2:
                S += '...' + str(A[j]) + ','
            else:
                S += ',' + str(A[j]) + ','
    if F == 0:
        if N != 1:
            S += str(A[j+1])
        else:
            S = str(A[0])
    else:
        if L > 1:
            S += '...' + str(A[j + 1])
        else:
            S += ',' + str(A[j + 1])
    print(S)
