from math import log2


def checkMAX():
    global ANS, MAX
    if ((X & Z) * (Y & Z) > MAX or ((X & Z) * (Y & Z) == MAX and Z < ANS)) and L <= Z <= R:
        ANS = Z
        MAX = (X & Z) * (Y & Z)


for _ in range(int(input())):
    X, Y, L, R = map(int, input().split())
    if X and Y and R:
        Z = X | Y
        Z &= (1 << (int(log2(R)) + 1)) - 1
        ANS = Z
        if Z > R:
            T = Z
            MAX = 0
            D = Z - R
            B = int(log2(D))
            while Z & (1 << B):
                Z &= ~(1 << B)
                D &= ~(1 << B)
                if D > 0:
                    B = int(log2(D))
            if Z > R:
                while Z & (1 << B) == 0:
                    B += 1
                Z &= ~(1 << B)
            checkMAX()
            D = T - R
            while D < T:
                Z = T
                LSBD = int(log2(D & -D))
                while D & (1 << LSBD):
                    D &= ~(1 << LSBD)
                    LSBD += 1
                D |= (1 << LSBD)
                Z -= D
                checkMAX()
        if (X & ANS) * (Y & ANS):
            print(ANS)
        else:
            print(0)
    else:
        print(0)
