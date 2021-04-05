def main() :
	s = input()
	s1 = s[::-1]
	flag = 1
	x = int(len(s)/2)
	for i in range(x) :
	    if (s[i] != s1[i]) :
	        flag = 0
	        print("NO")
	        break
	if (flag == 1) :
	    print("YES")

if __name__ == "__main__" :
	main()