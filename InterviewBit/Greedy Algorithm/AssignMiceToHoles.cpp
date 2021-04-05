int Solution::mice(vector<int> &mice, vector<int> &holes) {
	sort(mice.begin(), mice.end());
	sort(holes.begin(), holes.end());
	int ans = INT_MIN;
	int n = mice.size();
	for (int i = 0; i < n; i++) {
		ans = max(ans, abs(mice[i] - holes[i]));
	}
	return ans;
}
