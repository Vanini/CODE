import os
for i in range(1,16):
	os.system("./seq <seq%d.in >seq%d.out"%(i,i))

