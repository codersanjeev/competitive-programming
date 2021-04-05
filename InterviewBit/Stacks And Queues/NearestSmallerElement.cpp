vector<int> Solution::prevSmaller(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans(n, -1);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top() >= arr[i]) {
			st.pop();
		}
		if (!st.empty()) {
			ans[i] = st.top();
		}
		st.push(arr[i]);
	}
	return ans;
}
