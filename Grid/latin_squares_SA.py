import numpy as np

def vestigium(M, N):
    k = 0
    r = 0
    c = 0
    for i in range(N):
        k += M[i][i]
        if N != len(np.unique(M[i,:])):
            r += 1
        if N != len(np.unique(M[:,i])):
            c += 1

    return k, r, c

def main():
    T = int(input())
    for i in range(T):
        N = int(input())
        M = []
        for j in range(N):
            row = list(map(int,input().split()))
            M.append(row)
        k, r, c = vestigium(np.array(M), N)
        print("Case #%d: %d %d %d" % (i + 1, k, r, c))

main()