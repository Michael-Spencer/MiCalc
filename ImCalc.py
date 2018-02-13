#import string
import sys #command-line args
import curses.ascii #for cntrl chars
print("Welcome to the imaginary calculator")

#command-line arguments for the choice of parsing data (including filename, or not), or not
Parse = 0

try:
	if sys.argv[1] == "parse":
		print(sys.argv[1])
		print("Parsing selected")
		Parse = 1
	elif sys.argv[1] != "parse":
		print("parse not selected but other value seen")
		ParseAsk = input("Did you want to pass data, 1 for yes, 0 for no\n")
		print(ParseAsk, "PARSE", type(ParseAsk))
		
		if ParseAsk != str(0) or ParseAsk != str(1):
			#function for loop of incorrect parse entry
			def ParseAsker():
				val = input("Did you want to pass data!?!?!? 1 for yes, 0 for no!\n")
				if val == str(0) or val == str(1):
					return val
				else:
					ParseAsker()
			Parse = ParseAsker() #ask again for parse
except:
		print("Parse not selected, restart with \"parse\" command-line argument")

if Parse == 0:
	Input = input("Enter full problem\n")
	BracList = []
	PunctList = []
	NumList = [] #will include i's to begin with
	
	#need to filter out brackets first
	#need recursion
	#6*(6*(6*6))
	def BracketFind(StartIter, EndIter):
		for i in range(StartIter,EndIter):
				if Input[i] == "(":
					for i2 in range(i+1,EndIter):
						if Input[i2] == "(":
							BracketFind(i2,EndIter)
						elif Input[i2] == ")":
							BracList.append(Input[i:i2])
							Input[i]=str("R"+str(len(BracList)))
							for iRep in range(i+1,i2):
								Input[iRep]=0
							BracketFind(0,len(BracList))
		return
	

	BracketFind(0, len(Input))

	for i in range(0,len(Input)):
		if curses.ascii.ispunct(Input[i]):
			PunctList.append(Input[i])
		else:
			NumList.append(Input[i])
	
	ImTot = 0.0 #variables will hold final values
	ReTot = 0.0 
	
	for i in range(0,len(zList)):
		if "i" in zList[i]:
			if zList[i] == "i":
				ImTot+=1.
			else:
				ImTot += float(zList[i].rstrip("i"))
		else:
			ReTot += float(zList[i])

	print("Problem = (",ReTot,")+(",ImTot,")")

