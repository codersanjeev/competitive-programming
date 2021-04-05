class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size(), ans = -1;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};