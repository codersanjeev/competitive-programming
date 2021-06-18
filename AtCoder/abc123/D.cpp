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
    int X, Y, Z, K, A[1009], B[1009], C[1009];
    vector<int> vec;
    cin >> X >> Y >> Z >> K;
    for (int i = 0; i < X; i++) cin >> A[i];
    sort(A, A + X, greater<int>());
    for (int i = 0; i < Y; i++) cin >> B[i];
    sort(B, B + Y, greater<int>());
    for (int i = 0; i < Z; i++) cin >> C[i];
    sort(C, C + Z, greater<int>());

    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                if ((i + 1) * (j + 1) * (k + 1) <= K)
                    vec.push_back(A[i] + B[j] + C[k]);
                else
                    break;
            }
        }
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < K; i++) cout << vec[i] << endl;
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