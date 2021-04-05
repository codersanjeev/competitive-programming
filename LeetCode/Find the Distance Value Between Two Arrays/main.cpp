class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size(), m = arr2.size(), ans = 0;
        for (int i = 0; i < n; i++) {
        	bool good = true;
        	for (int j = 0; j < m; j++) {
        		if (abs(arr1[i] - arr2[j]) <= d) {
        			good = false;
        			break;
        		}
        	}
        	if (good) {
        		ans++;
        	}
        }
        return ans;
    }
};