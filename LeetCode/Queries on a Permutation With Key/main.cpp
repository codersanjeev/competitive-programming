class Solution {
  public:
	vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> ans, arr(m);
		for (int i = 0; i < m; i++) {
			arr[i] = i;
		}
		for (const auto &ele : queries) {
			int idx = arr[ele - 1];
			ans.push_back(arr[ele - 1]);
			for (int j = 0; j < m; j++) {
				if (arr[j] < idx) {
					arr[j]++;
				}
			}
			arr[ele - 1] = 0;
		}
		return ans;
	}
};