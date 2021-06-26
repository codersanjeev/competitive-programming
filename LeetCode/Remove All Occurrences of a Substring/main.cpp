class Solution {
   public:
    string removeOccurrences(string s, string part) {
        auto it = s.find(part);
        while (it != string::npos) {
            s = s.erase(it, part.size());
            it = s.find(part);
        }
        return s;
    }
};