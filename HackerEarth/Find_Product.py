def main() :
	n = int(input())
	lis = list(map(int, input().split()))
	ans = 1
	for i in lis :
	    ans = (ans*i)%1000000007
	print(ans)

if __name__ == "__main__" :
	main()