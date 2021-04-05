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
    int n, x = 0, y = 0, z = 0, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    if (x == 0 && y == 0 && z == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}