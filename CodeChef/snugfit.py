#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb 18 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A.sort()
    B.sort()
    S = 0
    for I in range(N):
        S += min(A[I], B[I])
    print(S)