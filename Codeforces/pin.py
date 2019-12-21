#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 12:00:00 2019

@author: divyanshvinayak
"""

from random import randrange
T = int(input())
for I in range(T):
    N = int(input())
    L = list(range(N))
    for J in range(N):
        L[J] = input()
    print(N-len(set(L)))
    print(L[0])
    for J in range(1, N):
        if L.count(L[J]) > 1:
            for X in range(0, 4):
                F = 0
                N = 0
                while(True):
                    Y = L[J][0:X]+str(randrange(0, 9))+L[J][X+1:]
                    N+=1
                    if Y not in L:
                        L[J] = Y
                        F = 1
                        break
                    if N == 9:
                        break
                if F == 1:
                    break
        print(L[J])
