#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int tot = 0;
    for (int i = 0; i < n; ++i) {
        tot += ((i / k) + 1) * v[i];
    }
    cout << tot << endl;
    return 0;
}
