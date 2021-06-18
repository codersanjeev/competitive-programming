
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> arr(N);
int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = 0;
        bool flag = false;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] != (i + 1)) {
                if ((i - 1) >= 0 && arr[i - 1] == (i + 1)) {
                    ans++;
                    swap(arr[i], arr[i - 1]);
                } else if ((i - 2) >= 0 && arr[i - 2] == (i + 1)) {
                    ans += 2;
                    arr[i - 2] = arr[i - 1];
                    arr[i - 1] = arr[i];
                    arr[i] = i + 1;
                } else {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "Too chaotic" : to_string(ans)) << "\n";
    }
    return 0;
}
