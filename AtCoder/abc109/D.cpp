#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define mod(x) (x % MOD + MOD) % MOD
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
	int n, m;
	read(n, m);
	vector<vector<int>> arr(n, vector<int>(m));
	vector<pair<pair<int, int>, pair<int, int>>> ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			read(arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (arr[i][j] & 1) {
				ans.push_back({{i + 1, j + 1}, {i + 1, j + 2}});
				arr[i][j + 1]++;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (arr[i][m - 1] & 1) {
			ans.push_back({{i + 1, m}, {i + 2, m}});
			arr[i + 1][m - 1]++;
		}
	}

	write(ans.size(), "\n");

	for (const auto &ele : ans) {
		write(ele.first.first, " ", ele.first.second, " ", ele.second.first, " ", ele.second.second, "\n");
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int tc = 1;
	// read(tc);

	for (int curr = 1; curr <= tc; curr++) solve(curr);

	return 0;
}