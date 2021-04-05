#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
        vector<string> ans;
        vector<int> freq(26, 0);
        for (const auto &b : B) {
            vector<int> temp(26, 0);
            for (const auto &ele : b) {
                temp[ele - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                freq[i] = max(freq[i], temp[i]);
            }
        }
        for (const auto &a : A) {
            vector<int> temp(26, 0);
            for (const auto &ele : a) {
                temp[ele - 'a']++;
            }
            bool good = true;
            for (int i = 0; i < 26; i++) {
                if (temp[i] < freq[i]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans.push_back(a);
            }
        }
        return ans;
    }

    bool isSubset(const string &a, const string &b) {
        vector<int> freq(27, 0);
        for (const auto &ele : b) {
            freq[ele - 'a']++;
        }
        for (const auto &ele : a) {
            freq[ele - 'a']--;
        }
        for (const auto &ele : freq) {
            if (ele < 0) return false;
        }
        return true;
    }
};