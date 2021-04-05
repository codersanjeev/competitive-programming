/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

bool f(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    bool flag = true;
    for (int i = n + 1; i < m; i++) {
        if (f(i)) {
            flag = false;
            break;
        }
    }
    if (flag && f(n) && f(m)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}