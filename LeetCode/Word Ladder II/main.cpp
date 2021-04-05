class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> seen;
        vector<vector<string>> ans;
        for (const auto& word : wordList) {
            seen[word] = INT_MAX;
        }
        queue<pair<string, vector<string>>> q;
        q.push({beginWord, {beginWord}});
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            string word = curr.first;
            auto currList = curr.second;
            if (word == endWord) {
                ans.push_back(currList);
                continue;
            }
            for (int i = 0; i < word.size(); i++) {
                string tempWord = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    tempWord[i] = ch;
                    if (tempWord == word || seen[tempWord] == 0 || seen[tempWord] < currList.size()) {
                        continue;
                    }
                    seen[tempWord] = currList.size();
                    currList.push_back(tempWord);
                    q.push({tempWord, currList});
                    currList.pop_back();
                }
            }
        }
        return ans;
    }
};