/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    while (i < n) {
        if (s[i] == '.') {
            cout << 0;
            i++;
        } else if (s[i] == '-' && s[i + 1] == '.') {
            cout << 1;
            i += 2;
        } else if (s[i] == '-' && s[i + 1] == '-') {
            cout << 2;
            i += 2;
        }
    }
    return 0;
}