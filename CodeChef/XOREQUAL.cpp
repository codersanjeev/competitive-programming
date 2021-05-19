#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int binpow(int x, int y) {
    if (y == 0) return 1LL;
    int ans = binpow(x, y / 2) % mod;
    ans = (ans * ans) % mod;
    return (y % 2 == 0 ? ans : (ans * x) % mod);
}

signed main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << binpow(2LL, N - 1) << "\n";
    }
    return 0;
}
