class Solution {
  public:
	bool canReach(vector<int> &arr, int start) {
		if (start < 0 || start >= arr.size() || arr[start] == arr.size()) {
			return false;
		}
		if (arr[start] == 0) {
			return true;
		}
		int x = arr[start];
		arr[start] = arr.size();
		return canReach(arr, start + x) || canReach(arr, start - x);
	}
};