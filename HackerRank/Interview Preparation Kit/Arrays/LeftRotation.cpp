
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> arr(N);
int n, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    rotate(arr.begin(), arr.begin() + d, arr.begin() + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
