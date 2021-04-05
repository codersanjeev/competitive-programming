string Solution::largestNumber(const vector<int> &A) {
	vector<string> arr;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		arr.push_back(to_string(A[i]));
	}
	sort(arr.begin(), arr.end(), [](const string & a, const string & b) -> bool{
		long ab = stol(a + b);
		long ba = stol(b + a);
		return ab > ba;
	});
	string ans;
	for (int i = 0; i < n; i++) {
		ans += arr[i];
	}
	while (ans.size() > 1 && ans[0] == '0') {
		ans = ans.substr(1);
	}
	return ans;
}