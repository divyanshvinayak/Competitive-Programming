#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 12:00:00 2019

@author: divyanshvinayak
"""

N = int(input())
Z = set()
for I in range(N):
    Z.add(''.join(set(input())))
Z = list(Z)
X = len(Z)
C = 0
for I in range(X):
    for J in range(X):
        if I != J:
            if len(set(Z[I]).intersection(set(Z[J]))) > 0:
                C += 1
                break
if C == 0:
    print(X - C)
else:
    print(X - C + 1)
