import numpy as np

def sum(l):
    return np.sum(l)

def main():
    T = int(input().strip())
    for i in range(T):
        N = int(input().strip())
        C = [int(x) for x in input().split()]
        res = sum(C)
        print("Case #%d: %s\n" % (i + 1, res))

main()