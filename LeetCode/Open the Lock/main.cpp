class Solution {
   public:
    int openLock(vector<string> &deadends, string target) {
        queue<string> q;
        q.push("0000");
        set<string> visited(deadends.begin(), deadends.end());
        int steps = -1;
        while (!q.empty()) {
            ++steps;
            int len = q.size();
            while (len--) {
                string currNode = q.front();
                q.pop();
                if (currNode == target) return steps;
                if (visited.count(currNode)) continue;
                visited.insert(currNode);
                for (int i = 0; i < 4; ++i) {
                    string prevNode = currNode, nextNode = currNode;
                    prevNode[i] = (currNode[i] == '0' ? '9' : currNode[i] - 1);
                    nextNode[i] = (currNode[i] == '9' ? '0' : currNode[i] + 1);
                    q.push(prevNode);
                    q.push(nextNode);
                }
            }
        }
        return -1;
    }
};