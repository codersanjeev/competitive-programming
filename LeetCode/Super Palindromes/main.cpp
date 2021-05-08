class Solution {
   public:
    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left), R = stoll(right);
        vector<long long> all = generateAllSuperPalindromes();
        long long ans = 0LL;
        for (const auto &ele : all) {
            if (ele > 1e9) continue;
            long long x = ele * ele;
            if (x >= L && x <= R && palindrome(x)) {
                ans++;
            }
        }
        return ans;
    }

   private:
    vector<long long> generateAllSuperPalindromes() {
        vector<long long> ans;
        for (long long i = 1; i <= 9; ++i) ans.push_back(i);
        for (long long i = 1; i <= 10000; ++i) {
            string s = to_string(i);
            string t = s;
            reverse(t.begin(), t.end());
            ans.push_back(stoll(s + t));
            for (long long j = 0; j <= 9; ++j) {
                string temp = s;
                temp += (j + '0');
                temp += t;
                ans.push_back(stoll(temp));
            }
        }
        return ans;
    }

    bool palindrome(long long x) {
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
};