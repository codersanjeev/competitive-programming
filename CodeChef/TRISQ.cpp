#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, b;
    cin >> t;
    while (t--) {
        cin >> b;
        int x = b / 2 - 1;
        cout << (x * (x + 1)) / 2 << "\n";
    }
    return 0;
}