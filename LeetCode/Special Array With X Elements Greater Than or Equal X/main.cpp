class Solution {
public:
    int specialArray(vector<int>& nums) {
		vector<int> freq(1001, 0);
        for (const auto &ele : nums) {
            freq[ele]++;
        }
        for (int i = 999; i >= 0; i--) {
        	freq[i] += freq[i + 1];
        	if (freq[i] == i) {
        		return i;
        	}
        }
        return -1;
    }
};