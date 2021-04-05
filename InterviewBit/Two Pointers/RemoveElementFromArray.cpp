int Solution::removeElement(vector<int> &arr, int ele) {
	int n = arr.size();
	int i = 0, j = 0;
	while (i < n) {
		if (arr[i] == ele) {
			i++;
		} else {
			arr[j] = arr[i];
			i++;
			j++;
		}
	}
	arr.resize(j);
	return j;
}
