#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
   public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int N = persons.size(), lead = -1;
        this->times = times;
        unordered_map<int, int> count;
        for (int i = 0; i < N; i++) {
            count[persons[i]]++;
            lead = count[persons[i]] >= count[lead] ? persons[i] : lead;
            mp[times[i]] = lead;
        }
    }

    int q(int t) {
        auto it = upper_bound(times.begin(), times.end(), t);
        it--;
        return mp[*it];
    }

   private:
    vector<int> times;
    unordered_map<int, int> mp;
};