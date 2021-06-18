
#include <bits/stdc++.h>
using namespace std;

int arr[6][6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]);
        }
    }
    cout << ans;
    return 0;
}
