#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, x, k, N;
    cin >> T;
    while (T--) {
        cin >> N >> x >> k;
        if (x % k == 0 || (N + 1 - x) % k == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
