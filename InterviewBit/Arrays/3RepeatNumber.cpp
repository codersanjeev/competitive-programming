int Solution::repeatedNumber(const vector<int> &arr) {
	int n = arr.size();
	int y = -1, z = -1, cy = 0, cz = 0;
	for (auto x : arr) {
		if (y == x) {
			cy++;
		} else if (z == x) {
			cz++;
		} else if (!cy) {
			y = x;
			cy = 1;
		} else if (!cz) {
			z = x;
			cz = 1;
		} else {
			cy--;
			cz--;
		}
	}
	cy = 0;
	cz = 0;
	for (auto x : arr) {
		if (x == y) {
			cy++;
		} else if (x == z) {
			cz++;
		}
	}
	if (cy > n / 3) {
		return y;
	}
	if (cz > n / 3) {
		return z;
	}
	return -1;
}
