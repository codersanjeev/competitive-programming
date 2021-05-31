#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    if (arr[0] == arr[1]) {
        cout << arr[2];
    } else if (arr[1] == arr[2]) {
        cout << arr[0];
    } else {
        cout << 0;
    }
    return 0;
}