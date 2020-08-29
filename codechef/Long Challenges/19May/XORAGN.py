def get_double_value(a):
	return 2*a
	
t= input()

while t>0:
	t-=1
	_x = input()

	a = map(int, raw_input().split())
	a = map(get_double_value, a)
	ans = 0
	for ele in a:
		ans = ans^ele
	
	print ans