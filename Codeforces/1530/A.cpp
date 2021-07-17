#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 1;
        while (n > 0) {
            ans = max(ans, n % 10);
            n /= 10;
        }
        cout << ans << "\n";
    }
    return 0;
}