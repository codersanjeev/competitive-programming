class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);
        for (const auto &ele : arr1) {
        	freq[ele]++;
        }
        int n = arr1.size(), k = 0;
        vector<int> ans(n);
        for (const auto &ele : arr2) {
        	while (freq[ele] > 0) {
        		ans[k++] = ele;
        		freq[ele]--;
        	}
        }
        for (int i = 0; i < 1001; i++) {
            while (freq[i]--) {
                ans[k++] = i;
            }
        }
        return ans;
    }
};