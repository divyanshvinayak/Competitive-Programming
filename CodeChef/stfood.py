#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 26 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    Z = set()
    for _ in range(int(input())):
        S, P, V = map(int, input().split())
        Z.add(P // (S + 1) * V)
    print(max(Z))
