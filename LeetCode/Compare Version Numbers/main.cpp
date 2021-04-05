class Solution {
   public:
    int compareVersion(string version1, string version2) {
        vector<int> versionOne = splitString(version1);
        vector<int> versionTwo = splitString(version2);
        int n = min(versionOne.size(), versionTwo.size());
        int i = 0;
        for (i = 0; i < n; i++) {
            if (versionOne[i] < versionTwo[i]) {
                return -1;
            } else if (versionOne[i] > versionTwo[i]) {
                return 1;
            }
        }
        if (versionOne.size() < versionTwo.size()) {
            while (i < versionTwo.size()) {
                if (versionTwo[i] > 0) {
                    return -1;
                }
                i++;
            }
        } else if (versionOne.size() > versionTwo.size()) {
            while (i < versionOne.size()) {
                if (versionOne[i] > 0) {
                    return 1;
                }
                i++;
            }
        }
        return 0;
    }

   private:
    vector<int> splitString(const string &s) {
        istringstream ss(s);
        string word;
        vector<int> ans;
        while (getline(ss, word, '.')) {
            int curr = stoi(word);
            ans.push_back(curr);
        }
        return ans;
    }
};