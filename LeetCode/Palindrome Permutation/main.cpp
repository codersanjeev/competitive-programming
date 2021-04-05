class Solution {
   public:
    bool canPermutePalindrome(string s) {
        vector<int> freq(257, 0);
        for (const auto &ch : s) {
            freq[ch]++;
        }
        int odd = 0;
        for (const auto &ele : freq) {
            if (ele % 2 == 1) {
                odd++;
            }
        }
        return odd <= 1;
    }
};