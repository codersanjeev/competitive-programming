class Solution {
   public:
    int maxNumberOfApples(vector<int>& arr) {
        int capacity = 5000, curr = 0, ans = 0;
        sort(arr.begin(), arr.end());
        for (const auto& ele : arr) {
            if (curr + ele > capacity) {
                break;
            } else {
                curr += ele;
                ans++;
            }
        }
        return ans;
    }
};