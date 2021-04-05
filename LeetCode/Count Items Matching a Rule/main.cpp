#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for (const auto& item : items) {
            if (ruleKey == "type" && ruleValue == item[0]) {
                ans += 1;
            } else if (ruleKey == "color" && ruleValue == item[1]) {
                ans += 1;
            } else if (ruleKey == "name" && ruleValue == item[2]) {
                ans += 1;
            }
        }
        return ans;
    }
};