#include <bits/stdc++.h>
using namespace std;

class TimeMap {
   public:
    TimeMap() {
        mp.clear();
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        auto &it = mp[key];
        auto ans = upper_bound(it.begin(), it.end(), timestamp, [](int val, auto &p) {
            return val < p.first;
        });
        return ans == it.begin() ? "" : prev(ans)->second;
    }

   private:
    unordered_map<string, vector<pair<int, string>>> mp;
};