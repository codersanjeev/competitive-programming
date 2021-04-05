freq = {}
while True :
	try :
		text = input()
		words = text.split(" ")
		for word in words :
			freq[word] = freq.get(word, 0) + 1
	except EOFError :
		break

ans = {}

for k, v in freq.items() :
	ans[v] = ans.get(v, []) + [k]

for k, v in sorted(ans.items()) :
	print(k, end = ' ')
	cnt = 0
	for w in sorted(v) :
	    if w is not '' and cnt < len(v) - 1 :
	        print(w, end = ' ')
        elif w is not '' :
            print(w)
        cnt = cnt + 1

