string Solution::convert(string word, int rows) {
	int n = word.size();
	if (rows == 1) {
		return word;
	}
	vector<string> arr(rows);
	int curr = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		arr[curr].push_back(word[i]);
		if (curr == rows - 1) {
			flag = false;
		}
		if (curr == 0) {
			flag = true;
		}
		if (flag) {
			curr++;
		} else {
			curr--;
		}
	}
	string ans = "";
	for (auto ele : arr) {
		ans += ele;
	}
	return ans;
}
