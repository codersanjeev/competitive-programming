int Solution::removeDuplicates(vector<int> &arr) {
	int n = arr.size();
	if (n == 0 || n == 1) {
		return n;
	}
	int j = 0, i = 0;
	while (i < n - 1) {
		if (arr[i] != arr[i + 1]) {
			arr[j] = arr[i];
			j++;
		}
		i++;
	}
	arr[j] = arr[n - 1];
	return j + 1;
}
