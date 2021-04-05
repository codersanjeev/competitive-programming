bad = ['!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', '{', '}', '[', ']', ';', ':', '\'', '"', '`', '/', '>', '?', '.', ',', '<', '~', '|' '\\']

while True :
	try :
		text = input()
		for i in text :
			if i not in bad and i is not '|' and i is not '\\' :
				print(i, end = "")
		print()
	except EOFError :
		break
