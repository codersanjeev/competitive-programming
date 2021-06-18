class Solution {
   private:
    bool isSubsequence(const string &s1, const string &s2) {
        int n = s1.size(), m = s2.size(), j = 0;
        if (n > m) return false;
        if (n == m) return s1 == s2;
        if (m == 0) return false;
        if (n == 0) return true;
        for (int i = 0; i < m; i++) {
            if (s1[j] == s2[i]) {
                if (j == n - 1) return true;
                j++;
            }
        }
        return false;
    }

   public:
    int maximumRemovals(string s, string p, vector<int> &removable) {
        int lo = 0, hi = removable.size(), ans = 0;
        auto good = [&](int rem) -> bool {
            string temp = s;
            for (int i = 0; i < rem; ++i) {
                s[removable[i]] = '/';
            }
            bool res = isSubsequence(p, s);
            s = temp;
            return res;
        };
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (good(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};