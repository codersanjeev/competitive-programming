auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    	int curr = 1, cnt = 0;
    	set<int> st(arr.begin(), arr.end());
    	for (int i = 1; i <= 100000; i++) {
    		if (st.count(i) == 0) {
    			cnt++;
    			curr = i;
    		}
    		if (cnt == k) return curr;
    	}
    	return curr;
    }
};