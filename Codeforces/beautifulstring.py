#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 12:00:00 2019

@author: divyanshvinayak
"""

Z = int(input())
for I in range(Z):
    S = list(input())
    F = 0
    X = len(S)
    if S[0] == '?':
        try:
            if S[1] != 'a':
                S[0] = 'a'
            elif S[1] != 'b':
                S[0] = 'b'
            else:
                S[0] = 'c'
        except:
            S[0] = 'a'
    for J in range(0, X-1):
        if S[J] == S[J+1] != '?':
            print(-1)
            F = 1
            break
        elif S[J] == '?':
            if S[J-1] != 'a' and S[J+1] != 'a':
                S[J] = 'a'
            elif S[J-1] != 'b' and S[J+1] != 'b':
                S[J] = 'b'
            else:
                S[J] = 'c'
    if S[X-1] == '?':
        if S[X-2] != 'a':
            S[X-1] = 'a'
        elif S[X-2] != 'b':
            S[X-1] = 'b'
        else:
            S[X-1] = 'c'
    if F == 0:
        print(''.join(S))
