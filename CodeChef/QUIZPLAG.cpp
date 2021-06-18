#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, M, K, ele;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        map<int, int> mp;
        while (K--) {
            cin >> ele;
            mp[ele]++;
        }
        vector<int> ans;
        for (const auto &ele : mp) {
            if (ele.first >= 1 && ele.first <= N && ele.second > 1) {
                ans.push_back(ele.first);
            }
        }
        cout << ans.size() << " ";
        for (const auto &ele : ans) cout << ele << " ";
        cout << "\n";
    }
    return 0;
}