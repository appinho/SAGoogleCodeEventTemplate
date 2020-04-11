"""
t, w = readline_int_list()   // Reads 50 into t and 6 into w
printline 3 to stdout        // Asks about day 3.
flush stdout
n = readline_int()           // Reads 15 into n.
printline 1 to stdout        // Asks about day 1.
flush stdout
n = readline_int()           // Reads 7 into n.
printline 1 1 1 3 0 0 to stdout
flush stdout                 // We make a guess even though we could have
                             // queried the well up to four more times.
verdict = readline_int()     // Reads -1 into verdict (judge has decided our
                             //   solution is incorrect)
exit                         // Exits to avoid an ambiguous TLE error 
"""
import sys
import math
mod = 63

def solve(W):

  l = [1,1,1,1,1,1]
  for w in range(5, -1, -1):
    guess = w * mod
    if(guess == 0):
      guess = 1
    print(guess)
    sys.stdout.flush()
    n = int(raw_input())
    #assert n != -1
    for i in range(5, w, -1):
      n = n - l[i] * (pow(2, guess/(i + 1)))
    l[w] = n / (pow(2, guess/(w+1)))
  print(" ".join(map(str, l)))
  sys.stdout.flush()
  verdict = int(raw_input())
  #assert verdict != -1

T, W = map(int, raw_input().split())
#print(T)
for _ in range(T):
  solve(W)