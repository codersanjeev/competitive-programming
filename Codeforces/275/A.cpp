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
    vector<vector<int>> arr(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = arr[i][j];
            if (i - 1 >= 0) {
                sum += arr[i - 1][j];
            }
            if (j - 1 >= 0) {
                sum += arr[i][j - 1];
            }
            if (i + 1 < 3) {
                sum += arr[i + 1][j];
            }
            if (j + 1 < 3) {
                sum += arr[i][j + 1];
            }
            cout << ((sum % 2) == 0) ? 1 : 0;
        }
        cout << "\n";
    }
    return 0;
}