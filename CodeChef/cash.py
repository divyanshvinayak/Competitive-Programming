#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 18 12:00:00 2020

@author: divyanshvinayak
"""

for _ in range(int(input())):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    print(sum(A) % K)