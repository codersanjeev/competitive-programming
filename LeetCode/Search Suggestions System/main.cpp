class Trie {
   public:
    vector<Trie *> children;
    vector<string> suggestion;

    Trie() {
        children.resize(26, nullptr);
    }
};

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string word) {
        sort(products.begin(), products.end());
        Trie *trie = new Trie();
        for (const auto &ele : products) {
            Trie *node = trie;
            for (const auto &ch : ele) {
                if (node->children[ch - 'a'] == nullptr) {
                    node->children[ch - 'a'] = new Trie();
                }
                node = node->children[ch - 'a'];
                if (node->suggestion.size() < 3) {
                    node->suggestion.push_back(ele);
                }
            }
        }
        vector<vector<string>> ans;
        for (const auto &ch : word) {
            if (trie != nullptr) {
                trie = trie->children[ch - 'a'];
                if (trie == nullptr) {
                    ans.push_back({});
                } else {
                    ans.push_back(trie->suggestion);
                }
            } else {
                ans.push_back({});
            }
        }
        return ans;
    }
};