#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

void solve(int tc) {
    int N, M, A, B;
    cin >> N >> M;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        arr[i] = make_pair(A, B);
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        A = arr[i].first;
        B = arr[i].second;
        if (M >= B) {
            M -= B;
            ans += (A * B);
        } else {
            // M < B
            ans += (M * A);
            break;
        }
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // cin >> tc;
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}