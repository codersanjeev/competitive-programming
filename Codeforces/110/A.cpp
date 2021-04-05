/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

bool islucky(int n) {
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++) {
        // deb(s[i]);
        if (s[i] != '4' && s[i] != '7')
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '4' || s[i] == '7')
            cnt++;
    }
    // deb(cnt);
    if (islucky(cnt)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}