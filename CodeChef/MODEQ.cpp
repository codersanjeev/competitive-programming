#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int T, N, M;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vector<int> cnt(N + 1, 1);
        int ans = 0;
        for (int b = 2; b <= N; ++b) {
            ans += cnt[M % b];
            for (int a = M % b; a <= N; a += b) {
                ++cnt[a];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
