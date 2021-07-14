#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a, b;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> s;
        if (b >= 0) {
            cout << n * (a + b) << "\n";
        } else {
            int ops = 0;
            for (int i = 1; i < n; ++i) {
                if (s[i] != s[i - 1]) ++ops;
            }
            ops = (ops + 1) / 2;
            cout << n * a + (ops + 1) * b << "\n";
        }
    }
    return 0;
}