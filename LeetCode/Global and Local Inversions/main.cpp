class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) {
        	if (abs(A[i] - i) > 1) {
        		return false;
        	}
        }
        return true;
    }
};