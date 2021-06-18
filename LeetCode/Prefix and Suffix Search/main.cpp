#include <bits/stdc++.h>
using namespace std;

class WordFilter {
   private:
    unordered_map<string, int> mp;

   public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            vector<string> prefix, suffix;
            for (int j = 0; j <= word.size(); ++j) {
                prefix.push_back(word.substr(0, j));
                suffix.push_back(word.substr(j));
            }
            for (const auto& p : prefix) {
                for (const auto& s : suffix) {
                    mp[p + "$" + s] = max(mp[p + "$" + s], i);
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        if (mp.count(prefix + "$" + suffix) > 0) {
            return mp[prefix + "$" + suffix];
        } else {
            return -1;
        }
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */