class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    	int sma = accumulate(A.begin(), A.end(), 0);
    	int smb = accumulate(B.begin(), B.end(), 0);
    	set<int> st(B.begin(), B.end());
    	for (const auto &x : A) {
    		if ((smb - sma) % 2 == 0) {
	    		int y = x + (smb - sma) / 2;
	    		if (st.count(y) > 0) {
	    			return {x, y};
	    		}
	    	}
    	}
    	return {};
    }
};