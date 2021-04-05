vector<vector<int>> Solution::combine(int n, int k) {
	vector<vector<int>> ans;
	vector<int> temp(k, 0);
	int level = 0, maxLevel = k - 1, level_0_max = n - k + 1;
	while (level >= 0) {
		if (++temp[level] > level_0_max + level) {
			level--;
		} else if (level == maxLevel) {
			ans.push_back(temp);
		} else {
			temp[level + 1] = temp[level];
			level++;
		}
	}
	return ans;
}
