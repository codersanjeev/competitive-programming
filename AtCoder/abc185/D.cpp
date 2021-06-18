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
	vector<int> arr(m);
	readContainer(arr);

	if (m == 0) {
		write(1);
		return;
	}

	sort(arr.begin(), arr.end());
	vector<int> stamps;

	if (arr[0] > 1) {
		stamps.push_back(arr[0] - 1);
	}

	for (int i = 1; i < m; i++) {
		if (arr[i] - arr[i - 1] - 1 > 0) {
			stamps.push_back(arr[i] - arr[i - 1] - 1);
		}
	}

	if (arr[m - 1] < n) {
		stamps.push_back(n - arr[m - 1]);
	}

	if (stamps.size() == 0) {
		write(0);
		return;
	}

	sort(stamps.begin(), stamps.end());
	int ans = 0, w = stamps[0];

	for (int i = 0; i < stamps.size(); i++) {
		if (stamps[i] % w == 0) {
			ans += stamps[i] / w;

		} else {
			ans += ((stamps[i] / w) + 1);
		}
	}

	write(ans);
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