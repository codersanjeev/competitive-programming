class Solution {
   public:
    bool isArmstrong(int N) {
        vector<int> digits = getAllDigits(N);
        int k = digits.size();
        int curr = 0;
        for (const auto &ele : digits) {
            curr += power(ele, k);
        }
        return curr == N;
    }

   private:
    vector<int> getAllDigits(int N) {
        vector<int> ans;
        while (N > 0) {
            ans.push_back(N % 10);
            N /= 10;
        }
        return ans;
    }

    int power(int n, int m) {
        int ans = 1;
        while (m--) {
            ans *= n;
        }
        return ans;
    }
};