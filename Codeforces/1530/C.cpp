#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &ele : a) cin >> ele;
        for (auto &ele : b) cin >> ele;
        sort(begin(a), end(a), greater<int>());
        sort(begin(b), end(b), greater<int>());
        auto good = [&](int extra) {
            int contests = n + extra;
            contests = contests - (contests / 4);
            int myCount = 0, myScore = 0, oppCount = 0, oppScore = 0;
            for (int i = 0; i < extra; ++i) {
                if (myCount < contests) {
                    myScore += 100;
                    ++myCount;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (myCount < contests) {
                    myScore += a[i];
                    ++myCount;
                }
                if (oppCount < contests) {
                    oppScore += b[i];
                    ++oppCount;
                }
            }
            return myScore >= oppScore;
        };
        int lo = 0, hi = 1e5, ans = 1e5;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (good(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}