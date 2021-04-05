int Solution::removeDuplicates(vector<int> &arr) {
	int n = arr.size();
	if (n == 0 || n == 1 || n == 2) {
		return n;
	}
	int i = 2, j = 2;
	while (j < n) {
		if (arr[i - 1] == arr[j] && arr[i - 2] == arr[j]) {
			j++;
		} else {
			arr[i] = arr[j];
			i++;
			j++;
		}
	}
	return i;
}
