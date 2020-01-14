#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 14 12:00:00 2020

@author: divyanshvinayak
"""

T = int(input())
for I in range(T):
    N = int(input())
    A = int(input())
    S = 2 * 10 ** N + A
    print(S, flush=True)
    B = int(input())
    C = 10 ** N - B
    print(C, flush=True)
    D = int(input())
    E = 10 ** N - D
    print(E, flush=True)
    R = int(input())
    if R == -1:
        break