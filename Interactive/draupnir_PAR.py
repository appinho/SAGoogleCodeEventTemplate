# CJ19/1A
# MIDDLE
# Modulo/Power of two/Evolution

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