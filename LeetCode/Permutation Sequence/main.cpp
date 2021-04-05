class Solution {
   public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n), nums;
        factorial[0] = 1;
        nums.push_back(1);
        for (int i = 1; i < n; i++) {
            factorial[i] = i * factorial[i - 1];
            nums.push_back(i + 1);
        }
        string ans = "";
        k--;
        for (int i = 0; i < n; i++) {
            int index = k / factorial[n - i - 1];
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= factorial[n - i - 1];
        }
        return ans;
    }
};