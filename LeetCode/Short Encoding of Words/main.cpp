#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        for (const auto& word : st) {
            for (int i = 1; i < (int)word.size(); i++) {
                st.erase(word.substr(i));
            }
        }
        int ans = 0;
        for (const auto& word : st) {
            ans += (int)word.size();
            ans++;
        }
        return ans;
    }
};