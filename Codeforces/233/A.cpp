/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << -1;
    } else {
        cout << "2 1 ";
        for (int i = 3; i <= n; i += 2)
            cout << i + 1 << " " << i << " ";
    }
    return 0;
}