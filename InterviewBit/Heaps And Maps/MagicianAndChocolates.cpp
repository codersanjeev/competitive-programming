int Solution::nchoc(int k, vector<int> &arr) {
	priority_queue<int> pq;
	for (auto ele : arr) {
		pq.push(ele);
	}
	int ans = 0;
	int mod = 1e9 + 7;
	while (!pq.empty() && k--) {
		ans = (ans % mod + pq.top() % mod) % mod;
		int temp = pq.top();
		pq.pop();
		if (temp > 1) {
			pq.push(temp / 2);
		}
	}
	return ans % mod;
}
