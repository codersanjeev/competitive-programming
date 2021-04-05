class Solution {
  public:
	int kthGrammar(int N, int K) {
		if (N == 1 && K == 1) {
			return 0;
		}
		int M = ((1 << (N - 1)) >> 1);
		if (K <= M) {
			return kthGrammar(N - 1, K);
		} else {
			return kthGrammar(N - 1, K - M) ^ 1;
		}
	}

	// TLE :\
	// string kthGrammarUtil(string curr, int N) {
	// 	if (N == 1) {
	// 		return curr;
	// 	}
	// 	string ans = "";
	// 	for (const auto &ch : curr) {
	// 		if (ch == '0') {
	// 			ans += "01";
	// 		} else {
	// 			ans += "10";
	// 		}
	// 	}
	// 	return kthGrammarUtil(ans, N - 1);
	// }

};