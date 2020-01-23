#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 23 12:00:00 2020

@author: divyanshvinayak
"""

T, X = map(int, input().split())
A = {}
MIN = MAX = K = 0
MEX = []
for _ in range(T):
    Z = int(input())
    Z = (Z - MIN) % X + MIN
    while True:
        try:
            if A[Z]:
                Z += X
        except KeyError:
            A[Z] = 1
            break
    if Z > MAX:
        MAX = Z
    if Z == MIN:
        K = MIN + 1
        while K <= MAX + 1:
            try:
                if A[K]:
                    K += 1
            except KeyError:
                MIN = K
                break
    MEX.append(MIN)
print(*MEX, sep = '\n')
