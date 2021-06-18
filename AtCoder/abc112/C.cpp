#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, x[N], y[N], h[N];

int geth(int cx, int cy) {
    int res = -1, mx = -1;
    for (int i = 1; i <= n; i++) {
        int a = abs(cx - x[i]);
        int b = abs(cy - y[i]);
        if (res == -1) {
            if (h[i] == 0) {
                mx = max(mx, a + b);
            } else {
                res = a + b + h[i];
            }
        } else {
            if (max(res - a - b, 0) != h[i]) return -1;
        }
    }
    if (mx != -1 && res > mx) return -1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i] >> h[i];
    for (int cx = 0; cx <= 100; cx++)
        for (int cy = 0; cy <= 100; cy++) {
            int temp = geth(cx, cy);
            if (temp != -1) {
                cout << cx << " " << cy << " " << temp << endl;
                return 0;
            }
        }

    return 0;
}
