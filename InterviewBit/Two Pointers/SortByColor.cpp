void Solution::sortColors(vector<int> &arr) {
	int n = arr.size();
	int i = 0, j = 0, k = 0;
	for (auto ele : arr) {
		if (ele == 0) {
			i++;
		} else if (ele == 1) {
			j++;
		} else if (ele == 2) {
			k++;
		}
	}
	int x = 0;
	while (i--) {
		arr[x++] = 0;
	}
	while (j--) {
		arr[x++] = 1;
	}
	while (k--) {
		arr[x++] = 2;
	}
}
