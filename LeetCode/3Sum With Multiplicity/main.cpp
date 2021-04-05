#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int threeSumMulti(vector<int> &arr, int target) {
        const long long mod = (long long)1e9 + 7;
        long long ans = 0LL;
        unordered_map<long long, long long> indexes;
        for (const auto &ele : arr) {
            indexes[ele]++;
        }
        for (const auto &a : indexes) {
            for (const auto &b : indexes) {
                long long i = a.first, j = b.first, k = target - i - j;
                if (indexes.count(k) == 0) {
                    continue;
                }
                if (i == j && j == k) {
                    ans += (a.second * (a.second - 1) * (a.second - 2)) / 6;
                } else if (i == j) {
                    ans += ((a.second * (a.second - 1)) / 2) * indexes[k];
                } else if (i < j && j < k) {
                    ans += (a.second * indexes[j] * indexes[k]);
                }
                ans %= mod;
            }
        }
        return ans % mod;
    }
};