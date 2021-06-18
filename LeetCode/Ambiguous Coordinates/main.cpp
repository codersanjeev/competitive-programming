class Solution {
   public:
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.size() - 2);
        vector<string> answer;
        for (int i = 1; i < s.size(); ++i) {
            auto left = generateNumbers(s.substr(0, i));
            auto right = generateNumbers(s.substr(i));
            for (const auto &l : left) {
                for (const auto &r : right) {
                    answer.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return answer;
    }

   private:
    vector<string> generateNumbers(const string &s) {
        vector<string> answer;
        if (s[0] == '0' && s.back() == '0') {
            if (s.size() == 1) answer.push_back(s);
            return answer;
        }
        if (s[0] == '0') {
            answer.push_back("0." + s.substr(1));
        } else if (s.back() == '0') {
            answer.push_back(s);
        } else {
            answer.push_back(s);
            for (int i = 1; i < s.size(); ++i) {
                string num = s.substr(0, i) + "." + s.substr(i);
                answer.push_back(num);
            }
        }
        return answer;
    }
};