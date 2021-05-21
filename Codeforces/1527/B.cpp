#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int zeros = count(s.begin(), s.end(), '0'), flips = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1]) ++flips;
        }
        if (flips == 0) {
            if (zeros % 2 == 0 || zeros == 1) {
                cout << "BOB\n";
            } else {
                cout << "ALICE\n";
            }
        } else if (flips == 1) {
            if (zeros - 1 == 1) {
                cout << "DRAW\n";
            } else {
                cout << "ALICE\n";
            }
        } else {
            cout << "ALICE\n";
        }
    }
    return 0;
}