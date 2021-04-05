class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size(), mx = INT_MIN;
        char ans = '$';
        for (int i = 0; i < n; i++) {
        	int curr = releaseTimes[i];
        	if (i > 0) {
        		curr -= releaseTimes[i - 1];
        	}
        	if (curr > mx) {
        		mx = curr;
        		ans = keysPressed[i];
        	} else if (curr == mx) {
        		ans = max(ans, keysPressed[i]);
        	}
        }
        return ans;
    }
};