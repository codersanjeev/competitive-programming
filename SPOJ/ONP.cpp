/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    string s;
    cin >> t;
    unordered_map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 2;
    mp['*'] = 3;
    mp['/'] = 4;
    mp['^'] = 5;
    while (t--) {
        cin >> s;
        int n = s.size();
        string ans = "";
        stack<char> st;
        st.push('N');
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            } else if (s[i] == '(') {
                st.push('(');
            } else if (s[i] == ')') {
                while (st.top() != 'N' && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (st.top() == '(')
                    st.pop();
            } else {
                while (st.top() != 'N' && mp[s[i]] <= mp[st.top()]) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (st.top() != 'N') {
            ans += st.top();
            st.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}