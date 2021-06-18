#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    string s;
    cin >> q;
    while (q--) {
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1])
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
