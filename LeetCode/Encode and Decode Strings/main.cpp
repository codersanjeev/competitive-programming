class Codec {
   public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& arr) {
        string ans = "";
        for (const auto& ele : arr) {
            ans += ele;
            ans += '\0';
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        istringstream ss(s);
        vector<string> ans;
        string word;
        while (getline(ss, word, '\0')) {
            ans.push_back(word);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));