#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string toGoatLatin(string S) {
        istringstream ss(S);
        string word;
        int i = 1;
        string ans = "";
        string vowels = "aeiouAEIOU";
        while (getline(ss, word, ' ')) {
            if (i > 1) ans += " ";
            if (vowels.find(word[0]) != string::npos) {
                ans += word;
                ans += "ma";
            } else {
                ans += word.substr(1);
                ans += word[0];
                ans += "ma";
            }
            ans += string(i, 'a');
            i += 1;
        }
        return ans;
    }
};