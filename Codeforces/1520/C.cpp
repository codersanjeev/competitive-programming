#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << "1\n";
        } else if (n == 2) {
            cout << "-1\n";
        } else {
            vector<vector<int>> ans(n, vector<int>(n));
            int val = 1;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                for (int j = (flag ? 0 : 1); j < n; j += 2) {
                    ans[i][j] = val++;
                }
                flag = !flag;
            }
            flag = true;
            for (int i = 0; i < n; ++i) {
                for (int j = (flag ? 1 : 0); j < n; j += 2) {
                    ans[i][j] = val++;
                }
                flag = !flag;
            }
            for (const auto &x : ans) {
                for (const auto &y : x) {
                    cout << y << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}