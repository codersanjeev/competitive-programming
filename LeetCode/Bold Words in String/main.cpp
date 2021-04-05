class Solution {
   public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        vector<pair<int, int>> positions;
        for (const auto& word : words) {
            int m = word.size();
            for (int i = 0; (i = S.find(word, i)) != string::npos; i++) {
                positions.push_back(make_pair(i, i + m));
            }
        }
        sort(positions.begin(), positions.end());
        vector<pair<int, int>> mergedPositions;
        for (const auto& ele : positions) {
            if (mergedPositions.empty() || mergedPositions.back().second < ele.first) {
                mergedPositions.push_back(ele);
            } else {
                mergedPositions.back().second = max(mergedPositions.back().second, ele.second);
            }
        }
        reverse(mergedPositions.begin(), mergedPositions.end());
        for (const auto& ele : mergedPositions) {
            S.insert(ele.second, "</b>");
            S.insert(ele.first, "<b>");
        }
        return S;
    }
};