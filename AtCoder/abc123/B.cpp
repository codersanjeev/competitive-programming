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
    vector<int> A(5);
    cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];
    vector<int> P = {0, 1, 2, 3, 4};
    int final_answer = LLONG_MAX;
    do {
        int ans = 0;
        for (int i = 0; i < 5; ++i) {
            while (ans % 10 != 0) ans += 1;
            ans += A[P[i]];
        }
        final_answer = min(final_answer, ans);
    } while (next_permutation(P.begin(), P.end()));
    cout << final_answer << endl;
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