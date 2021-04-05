bool startsWith(string x, string y) {
	if (x.find(y) == 0) {
		return true;
	} else {
		return false;
	}
}

bool f(vector<string> &arr, int len) {
	string s = arr[0].substr(0, len);
	for (auto ele : arr) {
		if (!startsWith(ele, s)) {
			return false;
		}
	}
	return true;
}

string Solution::longestCommonPrefix(vector<string> &arr) {
	int n = arr.size();
	if (n == 0) {
		return "";
	}
	int lo = 1;
	int hi = INT_MAX;
	for (auto ele : arr) {
		hi = min(hi, (int)ele.size());
	}
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(arr, mid)) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return arr[0].substr(0, (lo + (hi - lo) / 2) - 1);
}
