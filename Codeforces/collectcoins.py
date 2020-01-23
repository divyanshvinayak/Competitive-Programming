#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 23 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    a, b, c, n = map(int, input().split())
    A = (b + c + n - 2 * a) / 3
    B = (a + c + n - 2 * b) / 3
    C = (a + b + n - 2 * c) / 3
    if A % 1 == 0 and B % 1 == 0 and C % 1 == 0 and A >= 0 and B >= 0 and C >= 0 and a + A == b + B == c + C:
        print('YES')
    else:
        print('NO')
