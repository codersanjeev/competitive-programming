#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream s(sentence);
        string word;
        int ans = 1;
        while (getline(s, word, ' ')) {
            if (isPrefix(searchWord, word)) {
                return ans;
            }
            ans += 1;
        }
        return -1;
    }

    bool isPrefix(const string &a, const string &b) {
        int n = a.size();
        int m = b.size();
        if (n > m) return false;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};