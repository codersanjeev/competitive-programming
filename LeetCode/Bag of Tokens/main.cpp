#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1, ans = 0;
        while (i <= j) {
            if (tokens[i] <= P) {
                ans++;
                P -= tokens[i++];
            } else if (ans >= 1 && i < j) {
                ans--;
                P += tokens[j--];
            } else {
                break;
            }
        }
        return ans;
    }
};