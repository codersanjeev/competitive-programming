class Solution {
   private:
    bool isSame(const string &word, const string &pattern) {
        unordered_map<char, char> wordMap, patternMap;
        for (int i = 0; i < word.size(); ++i) {
            char w = word[i], p = pattern[i];
            if (wordMap.count(w) == 0) wordMap[w] = p;
            if (patternMap.count(p) == 0) patternMap[p] = w;
            if (wordMap[w] != p || patternMap[p] != w) return false;
        }
        return true;
    }

   public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> ans;
        for (const auto &ele : words) {
            if (isSame(ele, pattern)) ans.push_back(ele);
        }
        return ans;
    }
};