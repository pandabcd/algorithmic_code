# your code goes here
t = input()

while t>0:
	t -=1
	n, k = map(int, raw_input().split())
	a = map(int, raw_input().split())
	
	# increase a2
	a1 = list(a[i] for i in range(0, len(a), 2))
	a2 = list(a[i] for i in range(1, len(a), 2))
	
	a1.sort()
	a2.sort()
	
	sum_a1 = sum(a1)
	sum_a2 = sum(a2)
	
	a1 = a1[::-1]
	
	for i in xrange(min((n-1)/2,k)):
		if a2[i] < a1[i]:
			sum_a1 += a2[i] - a1[i]
			sum_a2 += a1[i] - a2[i]
	
	if sum_a2 >sum_a1:
		print "YES"
	else:
		print "NO"
	