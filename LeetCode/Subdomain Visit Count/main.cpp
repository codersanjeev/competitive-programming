class Solution {
   public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string, int> h;
        for (const auto& s : cpdomains) {
            int pos = s.find(" ");
            int count = stoi(s.substr(0, pos));
            h[s.substr(pos + 1)] += count;
            for (int i = pos + 1; i < s.size(); i++)
                if (s[i] == '.') h[s.substr(i + 1)] += count;
        }
        for (auto m : h) res.push_back(to_string(m.second) + " " + m.first);
        return res;
    }
};