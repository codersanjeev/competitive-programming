class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if (arr.empty()) return 0;
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            ans += (((i + 1) * (n - i) + 1) / 2) * arr[i];
        }
        return ans;
    }
};