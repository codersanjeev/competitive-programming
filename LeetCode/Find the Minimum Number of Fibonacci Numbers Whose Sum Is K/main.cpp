class Solution {
  public:
	int findMinFibonacciNumbers(int k) {
		if (k < 2) return k;
		vector<int> fib;
		fib.push_back(1);
		fib.push_back(1);
		int curr = 1;
		while (curr <= k) {
			curr = fib[fib.size() - 1] + fib[fib.size() - 2];
			fib.push_back(curr);
		}
		return 1 + findMinFibonacciNumbers(k - fib[fib.size() - 2]);
	}
};