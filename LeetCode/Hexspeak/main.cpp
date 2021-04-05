class Solution {
   public:
    string toHexspeak(string num) {
        string hex = toHex(num);
        for (const auto &ele : hex) {
            if (ele >= '0' && ele <= '9') {
                return "ERROR";
            }
        }
        return hex;
    }

   private:
    vector<string> digit = {"O", "I", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    string toHex(string num) {
        long long n = stoll(num);
        string ans = "";
        while (n > 0) {
            int rem = n % 16;
            ans += digit[rem];
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};