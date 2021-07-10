#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y = 0;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &ele : a) cin >> ele;
    for (int i = 0; i < n; ++i) {
        y += a[i];
        if (i % 2 == 1) --y;
    }
    if (y <= x)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}