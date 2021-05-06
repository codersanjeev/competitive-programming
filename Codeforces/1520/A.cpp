#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        string x = "";
        x += s[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) x += s[i];
        }
        bool good = true;
        set<char> seen;
        for (const auto &ch : x) {
            if (seen.count(ch) > 0) {
                good = false;
                break;
            }
            seen.insert(ch);
        }
        cout << (good ? "YES\n" : "NO\n");
    }
    return 0;
}