class Solution {
  public:
	vector<int> pancakeSort(vector<int>& arr) {
		vector<int> ans;
		int n = arr.size();
		for (int target = n; target >= 1; target--) {
			if (arr[target - 1] == target) {
				continue;
			}
			int index = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i] == target) {
					index = i;
				}
			}
			ans.push_back(index + 1);
			int i = 0, j = index;
			while (i < j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
			if (arr[target - 1] == target) {
				continue;
			}
			ans.push_back(arr[0]);
			i = 0, j = arr[0] - 1;
			while (i < j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		return ans;
	}
};