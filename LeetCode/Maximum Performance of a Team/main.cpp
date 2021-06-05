template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

class Solution {
   public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        long ans = 0L, sum = 0L, mod = long(1e9 + 7);
        vector<pair<int, int>> teamMembers(n);
        for (int i = 0; i < n; ++i) {
            teamMembers[i].first = efficiency[i];
            teamMembers[i].second = speed[i];
        }
        sort(rbegin(teamMembers), rend(teamMembers));
        min_heap<int> heap;
        for (const auto &member : teamMembers) {
            heap.push(member.second);
            sum += long(member.second);
            if (heap.size() > k) {
                sum -= long(heap.top());
                heap.pop();
            }
            ans = max(ans, sum * member.first);
        }
        return ans % mod;
    }
};