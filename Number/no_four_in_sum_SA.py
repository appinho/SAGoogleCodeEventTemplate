t = int(raw_input())

def solve():

	price = raw_input()
	n = len(price)
	a = int(price)
	b = 0
	for i,p in enumerate(price):
		if p == '4':
			a -= 10**(n-i-1)
			b += 10**(n-i-1)
	return  str(a) + ' ' + str(b)

for __ in xrange(t):
	print "Case #%d: %s" % (__+1, solve())