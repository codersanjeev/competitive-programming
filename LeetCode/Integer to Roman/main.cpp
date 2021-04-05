class Solution {
   public:
    string intToRoman(int num) {
        int u = num % 10;
        int t = (num % 100) / 10;
        int h = (num % 1000) / 100;
        int th = num / 1000;
        return thousands[th] + hundreds[h] + tens[t] + units[u];
    }

   private:
    vector<string> units = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> thousands = {"", "M", "MM", "MMM"};
};