#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int N = popped.size(), i = 0;
        stack<int> st;
        for (const auto& ele : pushed) {
            st.push(ele);
            while (!st.empty() && i < N && st.top() == popped[i]) {
                st.pop();
                i++;
            }
        }
        return i == N;
    }
};