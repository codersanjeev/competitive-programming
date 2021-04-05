class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        for (int i = rounds[0]; i <= rounds[rounds.size() - 1]; i++) {
        	ans.push_back(i);
        }
        if (ans.size() > 0) {
        	return ans;
        }
        for (int i = 1; i <= rounds[rounds.size() - 1]; i++) {
        	ans.push_back(i);
        }
        for (int i = rounds[0]; i <= n; i++) {
        	ans.push_back(i);
        }
        return ans;
    }
};