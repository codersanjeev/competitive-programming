#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    map<int, int> mp;
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for (auto y : mp) {
        ans += (y.second / 2);
    }
    cout << ans;
    return 0;
}
