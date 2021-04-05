class Solution {
   public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st(candyType.begin(), candyType.end());
        int N = candyType.size();
        int M = st.size();
        return (M >= (N / 2) ? (N / 2) : M);
    }
};