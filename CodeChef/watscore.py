#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 12:00:00 2019

@author: divyanshvinayak
"""

T = int(input())
for i in range(T):
    N = int(input())
    D = {}
    for j in range(N):
        p, s = map(int, input().split())
        if p < 9:
            if p not in D:
                D[p] = s
            elif s > D[p]:
                D[p] = s
    print(sum(D.values()))
