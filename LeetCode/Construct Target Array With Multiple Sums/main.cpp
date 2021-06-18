class Solution {
   public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        long long sum = accumulate(target.begin(), target.end(), 0LL);
        priority_queue<long long> pq(target.begin(), target.end());
        while (pq.top() > 1) {
            long long oldMax = pq.top();
            pq.pop();
            if (sum - oldMax == 1) return true;
            long long newMax = ((2 * oldMax) - sum) % (sum - oldMax);
            if (newMax <= 0) return false;
            pq.push(newMax);
            sum -= oldMax;
            sum += newMax;
        }
        return true;
    }
};