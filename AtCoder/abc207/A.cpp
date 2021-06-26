#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(begin(arr), end(arr));
    cout << arr[1] + arr[2];
    return 0;
}