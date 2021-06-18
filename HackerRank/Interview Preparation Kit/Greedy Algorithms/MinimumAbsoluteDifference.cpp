#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (abs(arr[i] - arr[i + 1]) < ans)
            ans = abs(arr[i] - arr[i + 1]);
    }
    cout << ans;
    return 0;
}
