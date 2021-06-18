#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int temp = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U')
            ++temp;
        else
            --temp;
        if (temp == 0 && s[i] == 'U')
            ++ans;
    }
    cout << ans;
    return 0;
}
