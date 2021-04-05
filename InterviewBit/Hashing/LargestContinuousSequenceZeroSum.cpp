vector<int> Solution::lszero(vector<int> &arr) {
	unordered_map<int, int> mp;
	int sum = 0, maxLen = 0, maxIndex = 0, n = arr.size();
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (arr[i] == 0 && maxLen == 0) {
			maxLen = 1;
			maxIndex = i;
		}
		if (sum == 0) {
			maxLen = i + 1;
			maxIndex = i;
		}
		if (mp.find(sum) != mp.end()) {
			if (i - mp[sum] > maxLen) {
				maxLen = i - mp[sum];
				maxIndex = i;
			}
		} else {
			mp[sum] = i;
		}
	}
	vector<int> ans(maxLen);
	int k = 0;
	for (int i = maxLen - 1; i >= 0 && k < maxLen; i--) {
		ans[i] = arr[maxIndex - k];
		k++;
	}
	return ans;
}
