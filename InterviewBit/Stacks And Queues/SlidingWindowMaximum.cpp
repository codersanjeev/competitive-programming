vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
	int n = arr.size();
	if (k >= n) {
		return vector<int> {*max_element(arr.begin(), arr.end())};
	}
	vector<int> ans;
	deque<int> q;
	for (int i = 0; i < n; i++) {
		while (!q.empty() && q.front() < i - k + 1) {
			q.pop_front();
		}
		while (!q.empty() && arr[q.back()] < arr[i]) {
			q.pop_back();
		}
		q.push_back(i);
		if (i >= k - 1) {
			ans.push_back(arr[q.front()]);
		}
	}
	return ans;
}
