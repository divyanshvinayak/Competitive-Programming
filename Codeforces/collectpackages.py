#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 23 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    N = int(input())
    XY = list(range(N + 1))
    XY[0] = [0, 0]
    S = ''
    F = 1
    for I in range(1, N + 1):
        XY[I] = list(map(int, input().split()))
    XY.sort()
    for I in range(1, N + 1):
        DX = XY[I][0] - XY[I - 1][0]
        DY = XY[I][1] - XY[I - 1][1]
        if DX >= 0 and DY >= 0:
            S += 'R' * DX + 'U' * DY
        else:
            F = 0
            break
    if F == 1:
        print('YES')
        print(S)
    else:
        print('NO')
