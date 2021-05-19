class Solution {
   public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (const auto &path : paths) {
            istringstream ss(path);
            string directory, s;
            getline(ss, directory, ' ');
            while (ss >> s) {
                int index = s.find('(');
                string fileName = s.substr(0, index);
                string fullName = directory + "/" + fileName;
                string fileContents = s.substr(index + 1, s.find(')') - index - 1);
                mp[fileContents].push_back(fullName);
            }
        }
        for (const auto &ele : mp) {
            if (ele.second.size() > 1) ans.push_back(ele.second);
        }
        return ans;
    }
};
