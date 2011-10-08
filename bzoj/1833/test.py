class yy:
	def __init__(self, u = 9):
		self.a = u
	def __add__(self, o):
		return yy(self.a + o)

a = yy
c = a + 3
print c.a
