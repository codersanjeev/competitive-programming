class Solution {
   public:
    string customSortString(string order, string str) {
        unordered_map<char, int> orderMap;
        for (int i = 0; i < order.size(); ++i) {
            orderMap[order[i]] = i + 1;
        }
        sort(begin(str), end(str), [&](const char &a, const char &b) {
            return orderMap[a] < orderMap[b];
        });
        return str;
    }
};