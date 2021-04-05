string Solution::intToRoman(int num) {
	int a[7] = {1000, 500, 100, 50, 10, 5, 1};
	char b[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
	char res[25];
	int k = 0;
	for (int i = 0; i < 7; i += 2) {
		int c = num / a[i];
		if (c == 4) {
			res[k++] = b[i];
			res[k++] = b[i - 1];
		} else if (c == 9 && i != 0) {
			res[k++] = b[i];
			res[k++] = b[i - 2];
		} else if (c >= 5) {
			res[k++] = b[i - 1];
			for (int j = 0; j < c - 5; j++) {
				res[k++] = b[i];
			}
		} else {
			for (int j = 0; j < c; j++) {
				res[k++] = b[i];
			}
		}
		num -= c * a[i];
	}
	res[k] = '\0';
	return res;
}
