class Solution {
   public:
    int missingNumber(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0), n = arr.size(), actual = ((n + 1) * (arr[0] + arr[n - 1])) / 2;
        return actual - total;
    }
};