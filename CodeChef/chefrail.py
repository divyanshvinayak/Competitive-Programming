#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 18 12:00:00 2020

@author: divyanshvinayak
"""

from math import sqrt
def prime(n):
    d = 1
    c = 0
    while not n % 2:
        c += 1
        n /= 2
    if c % 2:
        d *= 2
    for k in range(3, int(sqrt(n)) + 1, 2):
        c = 0
        while not n % k:
            c += 1
            n /= k
        if c % 2:
            d *= k
    if n > 2:
        return d * n
    return d
P = list(range(100001))
for I in range(1, 100001):
    P[I] = prime(I)
A = int(input())
B = list(range(A))
for Q in range(A):
    N, M = map(int, input().split())
    X = list(map(int, input().split()))
    Y = list(map(int, input().split()))
    NX = {}
    PX = {}
    NY = {}
    PY = {}
    try:
        X.remove(0)
        Z = (N - 1) * M
    except:
        try:
            Y.remove(0)
            Z = N * (M - 1)
        except:
            Z = 0
    for I in X:
        if I > 0:
            try:
                PX[P[I]] += I,
            except:
                PX[P[I]] = [I]
        else:
            try:
                NX[P[-I]] += -I,
            except:
                NX[P[-I]] = [-I]
    for I in Y:
        if I > 0:
            try:
                PY[P[I]] += I,
            except:
                PY[P[I]] = [I]
        else:
            try:
                NY[P[-I]] += -I,
            except:
                NY[P[-I]] = [-I]
    for I in PX:
        if I in NX:
            for K in PX[I]:
                for L in NX[I]:
                    T = int(sqrt(K * L))
                    if P[T] in PY:
                        if T in PY[P[T]]:
                            Z += 1
                    if P[T] in NY:
                        if T in NY[P[T]]:
                            Z += 1
    for I in PY:
        if I in NY:
            for K in PY[I]:
                for L in NY[I]:
                    T = int(sqrt(K * L))
                    if P[T] in PX:
                        if T in PX[P[T]]:
                            Z += 1
                    if P[T] in NX:
                        if T in NX[P[T]]:
                            Z += 1
    B[Q] = Z
print(*B, sep = '\n')