while True :
	try :
		text = input()
		arr = text.split(',')
		for i in range(len(arr)) :
			if i == 4 :
				continue
			if i == 6 :
				print("+", end = "")
				print(arr[4], end = "-")
				print(arr[6], end = "")
			else :
				print(arr[i], end = ",")
		print()
	except EOFError :
		break
