#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < n - 1;) {
        if (arr[i + 2] == 0 && i + 2 < n) {
            ans++;
            i += 2;
        } else if (i + 1 < n) {
            ans++;
            i++;
        }
    }
    cout << ans;
    return 0;
}
