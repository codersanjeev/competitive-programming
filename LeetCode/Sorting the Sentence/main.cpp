class Solution {
   public:
    string sortSentence(string s) {
        istringstream ss(s);
        string word;
        vector<pair<int, string>> arr;
        while (getline(ss, word, ' ')) {
            int index = word.back() - '0';
            arr.push_back({index, word.substr(0, word.size() - 1)});
        }
        sort(arr.begin(), arr.end());
        string ans = "";
        for (const auto &ele : arr) {
            ans += ele.second;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};