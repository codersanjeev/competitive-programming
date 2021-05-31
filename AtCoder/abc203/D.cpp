#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> pond(n, vector<int>(n));
    for (auto &row : pond) {
        for (auto &ele : row) cin >> ele;
    }
    int ans = INT_MAX;
    for (int tli = 0; tli < n; ++tli) {
        if (tli + k > n) break;
        for (int tlj = 0; tlj < n; ++tlj) {
            if (tlj + k > n) continue;
            int bli = tli + k, blj = tlj + k;
            vector<int> temp;
            for (int i = tli; i < bli; ++i) {
                for (int j = tlj; j < blj; ++j) {
                    temp.push_back(pond[i][j]);
                }
            }
            sort(temp.begin(), temp.end());
            ans = min(ans, temp[temp.size() / 2]);
        }
    }
    cout << ans;
    return 0;
}