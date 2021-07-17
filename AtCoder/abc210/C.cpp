#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    for (auto &ele : c) cin >> ele;
    map<int, int> window;
    for (int i = 0; i < K; ++i) {
        window[c[i]]++;
    }
    int ans = window.size();
    for (int i = K; i < N; ++i) {
        window[c[i - K]]--;
        window[c[i]]++;
        if (window[c[i - K]] == 0) {
            window.erase(c[i - K]);
        }
        ans = max(ans, (int)window.size());
    }
    cout << ans;
    return 0;
}