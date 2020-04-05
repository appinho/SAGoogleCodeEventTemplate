import numpy as np

def nesting_depth(S):
    k = 0
    Sp = ""
    for s in S:
        c = int(s)
        diff = c - k
        if diff > 0:
            for _ in range(diff):
                Sp += "("
        elif diff < 0:
            for _ in range(-diff):
                Sp += ")"
        Sp += s
        k = int(s)
    diff = -k
    if diff > 0:
        for _ in range(diff):
            Sp += "("
    elif diff < 0:
        for _ in range(-diff):
            Sp += ")"

    return Sp

def main():
    T = int(input())
    for i in range(T):
        S = input()
        Sp = nesting_depth(S)
        print("Case #%d: %s" % (i + 1, Sp))

main()