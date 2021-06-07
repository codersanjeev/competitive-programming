#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0, ele;
    cin >> n;
    while (n--) {
        cin >> ele;
        ans += max(0, ele - 10);
    }
    cout << ans;
    return 0;
}