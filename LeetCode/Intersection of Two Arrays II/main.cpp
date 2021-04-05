class Solution {
  public:
	vector<int> intersect(vector<int> &x, vector<int> &y) {
		int n = x.size(), m = y.size(), i = 0, j = 0;
		vector<int> ans;
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		while (i < n && j < m) {
			if (x[i] == y[j]) {
				ans.push_back(x[i]);
				i++;
				j++;
			} else if (x[i] < y[j]) {
				i++;
			} else {
				j++;
			}
		}
		return ans;
	}
};