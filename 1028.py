n = input()

s = raw_input()
s = s.split()

flag = True

tList = []

for word in s:
	if (word == 'if'):
		tList.append("i")
		
	if (word == 'then'):
		if ((len(tList) > 0) and (tList[-1] == "i")):
			tList.pop()
			tList.append("t")
		else:
			flag = False
			break

	if (word == 'else'):
		if ((len(tList) > 0) and (tList[-1] == "t")):
			tList.pop()
		else:
			flag = False
			break

	if (word == 'begin'):
		if ((len(tList) > 0) and (tList[-1] == "i")):
			flag = False
			break
		else:
			tList.append("b")


	if (word == 'end'):
		while (len(tList) > 0 and tList[-1] == 't'):
			tList.pop()
		if ((len(tList) > 0) and (tList[-1] == "b")):
			tList.pop()
		else:
			flag = False
			break
			
while (len(tList) > 0 and tList[-1] == 't'):
	tList.pop()	
			
if (len(tList) > 0):
	flag = False

if (flag):
	print "YES"
else:
	print "NO"





