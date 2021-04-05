int Solution::singleNumber(const vector<int> &arr) {
	int ans = 0;
	int po = 0;
	for (int i = 0; i < 32; i++) {
		// 000010000 = (1 << i)
		// (1 << i) & ele --> tell if ith bit is set or not???
		int cnt = 0;
		for (auto ele : arr) {
			if ((1 << i) & ele) {
				cnt++;
			}
		}
		if (cnt % 3 != 0) {
			ans += pow(2, po);
		}
		po++;
	}
	return ans;
}
