import sys #for command-line arguments
from random import * #for random numbers

try:
	sys.argv[3]
except:
	print("Program requires command-line arguments of form:")
	print("python3 ImCreate.py 10 base.dat 3")
	exit()
	
ImMaxOut = int(sys.argv[1]) #Command-line argument to give total max complex number to be made
BaseFileName = sys.argv[2] #Command-line argument to give file name to be outputted
OutputTypes = int(sys.argv[3]) #clean, dirty, and mixed output selector

SufList = ["_clean","_dirty","_mixed"]
NameList = []

if OutputTypes > 1 and OutputTypes < 4:
	BaseName = BaseFileName.split(".") #split input string of base name and can add output type to name
	for i in range(1,OutputTypes+1): #have to index with 1 as way of input
		NameList.append(str(BaseName[0] + SufList[i-1] + "." + BaseName[1])) #makes descriptive names based on input base
else:
	print("OutputTypes value out of range")
	exit()
	
def WriteLoop(FileOut, InMaxOut, OutType):
	try:#to avoid seg faults
		ImOut = open(FileOut,'w') #Open ImOut.dat object - appending
		print("File",FileOut,"opened for output")
	except:
		print("File not opened")#catch block
	if OutType == 1:
		with ImOut:#targeted work
			for v in range(0,ImMaxOut): #this is clean formatting
				ReRand = "{0:.2f}".format(random()*randint(1,100)) #returns formatted string of random number
				ImRand = "{0:.2f}".format(random()*randint(1,100)) #2 d.p. which is enough
				ImOut.write(ReRand+"+"+ImRand+"i\n")#print formatted strings in nice way
	elif OutType == 2:
		with ImOut:
			for v in range(0,ImMaxOut): #this is clean formatting
				ReRand = "{0:.2f}".format(random()*randint(1,100)) #returns formatted string of random number
				ImRand = "{0:.2f}".format(random()*randint(1,100)) #2 d.p. which is enough
				ImOut.write(ReRand + " " + ImRand + "\n")#print formatted strings in nice way
	elif OutType == 3:
		with ImOut:
			for v in range(0,ImMaxOut): #this is clean formatting
				ReRand = "{0:.2f}".format(random()*randint(1,100)) #returns formatted string of random number
				ImRand = "{0:.2f}".format(random()*randint(1,100)) #2 d.p. which is enough
				if random() > 0.5:
					ImOut.write(ReRand+"+"+ImRand+"i\n")#print formatted strings in nice way
				else:
					ImOut.write(ReRand + " " + ImRand + "\n")#print formatted strings in nice way
	else:
		print("BIG PROBLEMS - OutputType number is unexpected")
	
	ImOut.close() #Have to close after doing stuff
	print("File",FileOut,"closed") #keeping user informed 
	return

for i in range(1,OutputTypes+1): #write to file based on output numbers
	WriteLoop(NameList[i-1], ImMaxOut, i)
    
