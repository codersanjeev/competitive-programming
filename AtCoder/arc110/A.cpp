#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int N;
    cin >> N;
    int ans = 1;
    for (int i = 2; i <= N; i++) ans = lcm(ans, i);
    cout << ans + 1;
    return 0;
}