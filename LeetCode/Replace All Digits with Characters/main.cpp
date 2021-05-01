class Solution {
   private:
    vector<char> alphabets;

    char shift(char c, int x) {
        int index = 0;
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] == c) {
                index = i;
                break;
            }
        }
        return alphabets[(index + x) % 26];
    }

   public:
    string replaceDigits(string s) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            alphabets.push_back(ch);
        }
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = shift(s[i - 1], s[i] - '0');
        }
        return s;
    }
};