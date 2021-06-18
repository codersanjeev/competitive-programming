#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string &s) {
    stack<char> st;
    for (const auto &ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (st.empty()) {
            return false;
        } else if (st.top() == '(' && ch == ')') {
            st.pop();
        } else if (st.top() == '{' && ch == '}') {
            st.pop();
        } else if (st.top() == '[' && ch == ']') {
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
}

int main() {
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        cout << (isBalanced(s) ? "YES\n" : "NO\n");
    }
    return 0;
}