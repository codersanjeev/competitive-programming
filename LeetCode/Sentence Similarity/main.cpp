class Solution {
   public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        unordered_map<string, set<string>> mp;
        for (const auto& ele : similarPairs) {
            mp[ele[0]].insert(ele[1]);
            mp[ele[1]].insert(ele[0]);
        }
        int n = sentence1.size(), m = sentence2.size();
        if (n != m) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            if (mp[sentence1[i]].count(sentence2[i]) == 0) {
                return false;
            }
        }
        return true;
    }
};