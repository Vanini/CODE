import os

for i in range(1,21):
	os.system("python source.py <%d.in >%d.out"%(i,i))

