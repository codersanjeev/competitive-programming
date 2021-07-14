#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    auto bad = [](const vector<int> &arr) -> bool {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (arr[i] >= arr[j] and arr[j] >= arr[k]) {
                        return true;
                    }
                    if (arr[i] <= arr[j] and arr[j] <= arr[k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    };
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (auto &ele : arr) cin >> ele;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = i; j < n; ++j) {
                temp.push_back(arr[j]);
                if (bad(temp)) break;
                ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}