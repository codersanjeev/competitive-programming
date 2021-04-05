int Solution::longestConsecutive(const vector<int> &arr) {
	int n = arr.size();
	unordered_set<int> st;
	for (auto ele : arr) {
		st.insert(ele);
	}
	int ans = INT_MIN;
	for (auto ele : arr) {
		int cnt = 1;
		if (st.find(ele - 1) == st.end()) {
			int temp = ele + 1;
			while (st.find(temp++) != st.end()) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	return ans;
}
