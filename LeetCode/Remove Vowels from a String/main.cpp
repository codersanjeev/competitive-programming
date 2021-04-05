class Solution {
   public:
    string removeVowels(string s) {
        string ans = "";
        for (const auto &ch : s) {
            if (isVowel(ch) == false) {
                ans += ch;
            }
        }
        return ans;
    }

   private:
    bool isVowel(const char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};