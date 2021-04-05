class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> freq(26, INT_MAX);
        for (const auto &ele : A) {
        	vector<int> cnt(26, 0);
        	for (const auto &ch : ele) {
        		cnt[ch - 'a']++;
        	}
        	for (int i = 0; i < 26; i++) {
        		freq[i] = min(freq[i], cnt[i]);
        	}
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
        	int cnt = freq[i];
        	while (cnt--) {
        		ans.push_back(string(1, i + 'a'));
        	}
        }
        return ans;
    }
};