int Solution::diffPossible(vector<int> &arr, int ele) {
	int i = 0, j = 0;
	int n = arr.size();
	while (i < n && j < n) {
		if (arr[j] - arr[i] == ele && i != j) {
			return 1;
		} else if (arr[j] - arr[i] < ele) {
			j++;
		} else {
			i++;
		}
	}
	return 0;
}
