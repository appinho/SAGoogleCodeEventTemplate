import sys

def solve(l, sold, count, N):
  if(len(l)==1):
    return -1, count
  else:
    for el in l[1::]:
      count[el] += 1

    min = N
    sol = -1
    for c in l[1::]:
      if not sold[c] and count[c] <= min:
        min = count[c]
        sol = c

    return sol, count


T = int(raw_input())
for _ in range(T):
  N = int(raw_input())
  sold = [False for _ in range(N)]
  count = [0 for _ in range(N)]
  for n in range(N):
    l = map(int, raw_input().split())
    guess, count = solve(l, sold, count, N)
    print guess
    sys.stdout.flush()
    sold[guess] = True
    #r = int(raw_input())
    #assert r != -1