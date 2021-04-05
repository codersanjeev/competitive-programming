/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int f(int x) {
    string s = to_string(x);
    set<char> st;
    for (int i = 0; i < 4; i++)
        st.insert(s[i]);
    return st.size() == 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ans = n + 1;
    while (1) {
        if (f(ans)) {
            cout << ans;
            break;
        } else {
            ans++;
        }
    }
    return 0;
}