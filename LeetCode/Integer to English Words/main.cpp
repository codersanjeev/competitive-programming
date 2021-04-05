class Solution {
   public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string ans = "";
        int index = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                string temp = "";
                helper(temp, num % 1000);
                ans = temp + THOUSANDS[index] + " " + ans;
            }
            index++;
            num /= 1000;
        }
        return trim(ans);
    }

   private:
    vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};
    vector<string> LESS_THAN_TWENTY = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    void helper(string &s, int num) {
        if (num == 0) {
            return;
        }
        if (num < 20) {
            s += LESS_THAN_TWENTY[num] + " ";
            return;
        } else if (num < 100) {
            s += TENS[num / 10] + " ";
            helper(s, num % 10);
        } else {
            s += LESS_THAN_TWENTY[num / 100] + " Hundred ";
            helper(s, num % 100);
        }
    }

    string trim(const string &s) {
        const int l = (int)s.length();
        int a = 0, b = l - 1;
        char c;
        while (a < l && ((c = s.at(a)) == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == '\0')) a++;
        while (b > a && ((c = s.at(b)) == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == '\0')) b--;
        return s.substr(a, 1 + b - a);
    }
};