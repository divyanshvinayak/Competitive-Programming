#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 26 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    N, a, b, c = map(int, input().split())
    F = list(map(int, input().split()))
    print(c + min({abs(b - F[I]) + abs(a - F[I]) for I in range(N)}))
