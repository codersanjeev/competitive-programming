bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
	sort(arrive.begin(), arrive.end());
	sort(depart.begin(), depart.end());
	int n = arrive.size();
	for (int i = 0; i < n; i++) {
		if ((i + K) < n && arrive[i + K] < depart[i]) {
			return 0;
		}
	}
	return 1;
}
