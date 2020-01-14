#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 14 12:00:00 2020

@author: divyanshvinayak
"""

T = int(input())
for I in range(T):
    S, X, Y, Z = map(int, input().split())
    if S >= X + Y + Z:
        print(1)
    elif S >= X + Y or S >= Y + Z:
        print(2)
    else:
        print(3)