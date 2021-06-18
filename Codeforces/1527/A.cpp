#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int l = (int)log2(n), temp = 1 << l, ans = 0;
        while (temp > 0) {
            if (temp % 2 == 0) {
                ans <<= 1;
                ans |= 1;
            }
            temp >>= 1;
        }
        cout << ans << "\n";
    }
    return 0;
}