class Solution {
   public:
    int reverse(int x) {
        string s = to_string(x);
        int index = 0, ans = 0, j = s.size() - 1;
        bool isNegative = false;
        if (s[0] == '-') {
            index = 1;
            isNegative = true;
        }
        while (j >= index) {
            if (ans > INT_MAX / 10) {
                return 0;
            }
            ans *= 10;
            ans += (s[j] - '0');
            j--;
        }
        return isNegative ? -ans : ans;
    }
};