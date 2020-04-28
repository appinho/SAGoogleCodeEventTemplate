# CJ17/Q
# HARD
# Greedy Bit Manipulation

t = int(raw_input())

def oversized_pancake_flippers(pancakes, K):

    A = []
    for i, a in enumerate(pancakes):
        if(a=='+'):
            A.append(1)
        else:
            A.append(0)
    # print(A)
    N = len(A)
    hint = [0] * N
    ans = flip = 0

    # When we flip a subarray like A[i], A[i+1], ..., A[i+K-1]
    # we can instead flip our current writing state, and put a hint at
    # position i+K to flip back our writing state.
    for i, x in enumerate(A):
        flip ^= hint[i]
        # print(i,flip,hint)
        if x ^ flip == 0:  # If we must flip the subarray starting here...
            ans += 1  # We're flipping the subarray from A[i] to A[i+K-1]
            # print("flip", ans)
            if i+K > N: return "IMPOSSIBLE"  # If we can't flip the entire subarray, its impossible
            flip ^= 1  
            if i+K < N: hint[i + K] ^= 1

    return str(ans)

for __ in xrange(t):
    s = raw_input()
    pancakes = s.split()[0]
    k = int(s.split()[1])
    print("Case #%d: %s" % (__+1, oversized_pancake_flippers(pancakes, k)))
