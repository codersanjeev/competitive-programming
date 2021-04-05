class Solution {
   public:
    vector<string> letterCasePermutation(string S) {
        int N = S.size();
        vector<string> answer;
        generatePermutation(S, 0, N, answer);
        answer = removeDuplicates(answer);
        return answer;
    }

   private:
    void generatePermutation(string &S, int index, int N, vector<string> &ans) {
        if (index == N) {
            ans.push_back(S);
            return;
        }
        char ch = S[index];
        generatePermutation(S, index + 1, N, ans);
        if (ch >= 'a' && ch <= 'z') {
            S[index] = (char)toupper(ch);
        } else {
            S[index] = (char)tolower(ch);
        }
        generatePermutation(S, index + 1, N, ans);
        S[index] = ch;
    }

    vector<string> removeDuplicates(const vector<string> &arr) {
        unordered_set<string> ans(arr.begin(), arr.end());
        return vector<string>(ans.begin(), ans.end());
    }
};