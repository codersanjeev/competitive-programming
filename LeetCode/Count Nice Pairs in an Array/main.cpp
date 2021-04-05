class Solution {
   public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const auto& ele : nums) {
            freq[ele - reversed(ele)] += 1;
        }
        long ans = 0LL;
        for (const auto& ele : freq) {
            long curr = ((long)ele.second * (long)(ele.second - 1)) >> 1LL;
            ans = (ans + curr) % mod;
        }
        return ans;
    }

   private:
    const int mod = 1e9 + 7;

    int reversed(int n) {
        int ans = 0;
        while (n > 0) {
            ans = (ans * 10) + (n % 10);
            n /= 10;
        }
        return ans;
    }
};