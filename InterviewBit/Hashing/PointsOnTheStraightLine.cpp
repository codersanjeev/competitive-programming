int Solution::maxPoints(vector<int> &A, vector<int> &B) {
	int n = A.size();
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	map<pair<double, double>, int> mp;
	double x1, y1, x2, y2;
	double m, c;
	int soln = 1;
	for (int i = 0; i < n - 1; i++) {
		x1 = A[i];
		y1 = B[i];
		for (int j = 0; j < n; j++) {
			if (j == i) {
				continue;
			}
			x2 = A[j];
			y2 = B[j];
			if (x2 == x1) {
				m = INT_MAX;
				c = x1;
			} else {
				m = (y2 - y1) / (x2 - x1);
				c = y1 - m * x1;
			}
			pair<double, double> p;
			p.first = m;
			p.second = c;
			if (mp.find(p) == mp.end()) {
				mp[p] = 2;
				soln = max(soln, mp[p]);
			} else {
				mp[p] += 1;
				soln = max(soln, mp[p]);
			}
		}
		mp.clear();
	}
	return soln;
}