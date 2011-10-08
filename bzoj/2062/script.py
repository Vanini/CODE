import os
import commands
while (True):
	os.system("./datamk")
	os.system("./check >1.out")
	os.system("./source >2.out")
	t,run = commands.getstatusoutput("diff -q 1.out 2.out")
	if t != 0:
		quit(0)
	print "Accepted"

