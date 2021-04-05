class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int curr = 0;
        for (const auto &ele : A) {
        	if (ele % 2 == 0) {
        		curr += ele;
        	}
        }
        for (const auto &query : queries) {
        	int index = query[1];
        	if (A[index] % 2 == 0) {
        		curr -= A[index];
        	}
        	A[index] += query[0];
        	if (A[index] % 2 == 0) {
        		curr += A[index];
        	}
        	ans.push_back(curr);
        }
        return ans;
    }
};