class Solution {
   public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> reachable;
        reachable.push(0);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                while (!reachable.empty() && reachable.front() < i - maxJump) reachable.pop();
                if (!reachable.empty() && reachable.front() <= i - minJump) reachable.push(i);
            }
        }
        return !reachable.empty() && reachable.back() == s.size() - 1;
    }
};