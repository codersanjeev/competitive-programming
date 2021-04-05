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

template <typename... T>
void read(T &... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

void solve(int tc) {
    string k;
    int d;
    read(k, d);
    int n = k.size();
    vector<vector<int>> dp(d, vector<int>(2, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
    	vector<vector<int>> temp(d, vector<int>(2, 0));
    	for (int s = 0; s < d; s++) {
    		for (bool ok : {true, false}) {
    			for (int digit = 0; digit < 10; digit++) {
    				if (digit > k[i] - '0' && !ok) {
    					break;
    				}
    				temp[(s + digit) % d][ok || (digit < k[i] - '0')] = (temp[(s + digit) % d][ok || (digit < k[i] - '0')] + dp[s][ok]) % mod;
    			}
    		}
    	}
    	dp = temp;
    }
    write((dp[0][0] + dp[0][1] - 1 + mod) % mod);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}