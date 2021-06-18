#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    vector<int> arr;
    for (int cnt = 1; cnt <= 9; ++cnt) {
        for (char ch = '1'; ch <= '9'; ++ch) {
            string s(cnt, ch);
            arr.push_back(stoi(s));
        }
    }
    sort(arr.begin(), arr.end());
    while (t--) {
        cin >> n;
        int lo = 0, hi = arr.size() - 1, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= n) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}