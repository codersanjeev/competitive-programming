#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, r;
    cin >> n >> r;
    long long arr[n];
    long long ans = 0;
    map<long long, long long> map1, map2;
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    for (long long i = 0; i < n; i++) {
        if (map2.count(arr[i]))
            ans += map2[arr[i]];
        if (map1.count(arr[i])) {
            map2[arr[i] * r] += map1[arr[i]];
        }
        map1[arr[i] * r]++;
    }
    cout << ans << "\n";
    return 0;
}
