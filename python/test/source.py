a = int(raw_input())
if (a == 1):
	def f(x):
		return g(x) * 2;
else:
	def f(x):
		return g(x) * 3
x = int(raw_input())
def g(x):
	return x + 1
print f(x)
