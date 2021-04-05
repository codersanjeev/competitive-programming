int subarraySumUtil(vector<int> &arr, int target) {
	unordered_map<int, int> mp;
	mp[0] = 1;
	int n = arr.size();
	int ans = 0;
	int sumSoFar = 0;
	for (int i = 0; i < n; i++) {
		sumSoFar += arr[i];
		int requiredSum = sumSoFar - target;
		if (mp.find(requiredSum) != mp.end()) {
			ans += mp[requiredSum];
		}
		mp[sumSoFar]++;
	}
	return ans;
}

int solveUtil(vector<vector<int>> &matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0) {
		return 0;
	}
	int rowLen = matrix.size();
	int colLen = matrix[0].size();
	int ans = 0;
	for (int left = 0; left < colLen; left++) {
		vector<int> tempArr(rowLen);
		for (int right = left; right < colLen; right++) {
			for (int row = 0; row < rowLen; row++) {
				tempArr[row] += matrix[row][right];
			}
			ans += subarraySumUtil(tempArr, target);
		}
	}
	return ans;
}

int Solution::solve(vector<vector<int>> &matrix) {
	return solveUtil(matrix, 0);
}
