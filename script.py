import numpy as np

def sum(l):
    return np.sum(l)

def main():
    T = int(input())
    for i in range(T):
        C = map(int, raw_input().split())
        res = sum(C)
        print("Case #%d: %s\n" % (i + 1, res))

if __name__ == '__main__':
	main()
