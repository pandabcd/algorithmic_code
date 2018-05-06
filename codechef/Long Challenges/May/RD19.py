# your code goes here
# your code goes here
def gcd(a, b):
	if b==0:
		return a
		
	return gcd(b, a%b)

t = input()

while(t>0):
	t-=1
	_x = input()
	a = map(int, raw_input().split())
	
	a.sort()
	a = a[::-1]
	
	ans = gcd(a[0], a[1])
	for i in xrange(2, len(a)):
		ans  = gcd(ans, a[i])
	
	
	if ans == 1:
		print 0
	else:
		print -1