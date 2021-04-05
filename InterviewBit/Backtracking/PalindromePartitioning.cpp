bool isPalindrome(string s) {
	string t = s;
	reverse(s.begin(), s.end());
	return s == t;
}

void f(int index, vector<string> &arr, vector<vector<string>> &ans, string s) {
	if (index == s.size()) {
		ans.push_back(arr);
		return;
	}
	string temp = "";
	for (int i = index; i < s.size(); i++) {
		temp += s[i];
		if (isPalindrome(temp)) {
			arr.push_back(temp);
			f(i + 1, arr, ans, s);
			arr.pop_back();
		}
	}
}

vector<vector<string>> Solution::partition(string s) {
	vector<vector<string>> ans;
	vector<string> arr;
	f(0, arr, ans, s);
	return ans;
}
